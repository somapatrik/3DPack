using System.Drawing;
using System.Reflection;
using optimal2dx;
using static System.Net.Mime.MediaTypeNames;

namespace _3DPack
{
    public class Truck
    {
        public string Name { get; private set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }
        public List<Floor> Floors { get; set; }
        private List<Package> toPack { get; set; }
        public List<Package> Packages { get; private set; }

        private Optimization2DX optimization2DX { get; set; }

        public int UsedArea
        {
            get
            {
                return Floors.Sum(f => f.UsedArea);
            }
        }

        private bool finishedOpt = false;
        private TaskCompletionSource<bool> _tcs;

        public static Truck Create(string name, int length, int width, int height)
        {
            var t = new Truck(length, width, height);
            t.SetName(name);
            return t;
        }

        public Truck(int length, int width, int height)
        {
            Width = width;
            Height = height;
            Length = length;

            Floors = new List<Floor>()
            {
                new Floor(length, width, height, new Point(0,0), 0)
            };

            Packages = new List<Package>();

            optimization2DX = new Optimization2DX();
            optimization2DX.OnFinish += Optimization2DX_OnFinish;
        }

        private void Optimization2DX_OnFinish()
        {
            int SheetIndex = 0;

            int top_x, top_y, bottom_x, bottom_y, thick;
            int repository_Index, repository_ID, demand_Index, demand_ID, rotated;

            double surf_covered;
            optimization2DX.SurfaceCovered(SheetIndex, out surf_covered, out repository_Index, out repository_ID);
            
            int NumPieces;
            optimization2DX.NumberOfUtilizedDemandPieces(SheetIndex, out NumPieces, out repository_Index, out repository_ID);
            for (int i = 0; i < NumPieces; i++)
            {
                optimization2DX.GetUtilizedDemandPiece(SheetIndex, i, out top_x, out top_y, out bottom_x, out bottom_y, out rotated, out repository_Index, out demand_Index, out repository_ID, out demand_ID);
                StoreOptimizidedPackage(demand_ID, repository_ID, top_x, top_y, bottom_x, bottom_y);
            }

            _tcs.SetResult(true);
        }

        public async void AreaOptimization(List<Package> packages, int floorId = 0)
        {
            toPack = new List<Package>();
            toPack = packages.Select(p => p.Clone()).ToList();
            var floor = Floors.FirstOrDefault(f => f.Id == floorId);
          
            if (floor != null)
            {
                //optimization2DX = new Optimization2DX();
                optimization2DX.BladeWidth = 0;
                optimization2DX.RandomSeed = 1;
                optimization2DX.OptimizationLevel = 50;

                // Set floor repository
                optimization2DX.NumberOfRepositoryPieces = 1;
                optimization2DX.SetRepositoryPiece(0, floor.Length, floor.Width, 0, 0, 0, 0, floor.Id, 0, 0);
                optimization2DX.NumberOfDemandPieces = toPack.Count;

                // Set packages
                int index = 0;
                foreach (var package in toPack.Where(p=>p.Height <= floor.Height))
                {
                    package.SetCutId(index);
                    optimization2DX.SetDemandPiece(index, package.Length, package.Width, 1, package.Cut_Id, 0);
                    index++;
                }

                _tcs = new TaskCompletionSource<bool>();
                optimization2DX.StartGuillotine();
                await _tcs.Task;

                FinishFloor(ref floor);
           }
        }

        private void StoreOptimizidedPackage(int packageCutId, int floorId, int topX, int topY, int bottomX, int bottomY)
        {
            var package = toPack.FirstOrDefault(p=>p.Cut_Id == packageCutId);
            var floor = Floors.FirstOrDefault(f=>f.Id == floorId);

            if (package != null && floor != null)
            {
                Point placementPoint = new Point(topX, topY);

                // Rotate package according to the optimalization
                int length = Math.Abs(bottomX - topX);

                if (package.Width == length)
                    package.Rotate();

                if (package.Length != length)
                    throw new Exception("Dimension error");

                floor.StorePackage(package, placementPoint);
                if (package.Stackable)
                    CreateNewFloor(floor.LevelHeight, placementPoint, package);

                toPack.Remove(package);
                Packages.Add(package);
            }


        }

        private void FinishFloor(ref Floor floor)
        {
            floor.Full = true;

            var availableFloors = Floors.Where(f => f.Full == false);
            
            if (toPack.Any() && availableFloors.Any())
            {
                AreaOptimization(toPack, availableFloors.OrderByDescending(f => f.LevelHeight).First().Id);
            }

        }

        /// <summary>
        /// Tries to place every package. 
        /// </summary>
        public void StorePackages(List<Package> packages)
        {
            List<PlacementResult> PotentionalPacking = new List<PlacementResult>();

            foreach (Package pack in packages)
            {
                foreach (Floor floor in Floors.Where(f => f.Height >= pack.Height))
                {
                    int ldmRemain = 0;
                    Point placementPoint = new Point();

                    if (floor.CheckPackagePlacement(pack, out placementPoint, out ldmRemain))
                    {
                        PotentionalPacking.Add(new PlacementResult()
                        {
                            Package = pack,
                            Floor = floor,
                            PlacementPoint = new Point(placementPoint.X, placementPoint.Y),
                            RemainingLDM = ldmRemain
                        });

                        break;
                    }
                }
            }

            var winner = PotentionalPacking.OrderByDescending(p => p.Package.LargerDimension).FirstOrDefault();

            if (winner != null)
            {
                winner.Floor.StorePackage(winner.Package, winner.PlacementPoint);

                if (winner.Package.Stackable)
                    CreateNewFloor(winner.Floor.LevelHeight, winner.PlacementPoint, winner.Package);

                Packages.Add(winner.Package);
                packages.Remove(winner.Package);
                StorePackages(packages);
            }
        }

        /// <summary>
        /// Tries to place 1 package to truck
        /// </summary>
        public bool InsertPackage(Package package)
        {
            List<Floor> newFloors = new List<Floor>();
            Point placementPoint = new Point();

            bool stored = false;

            foreach (Floor floor in Floors.Where(f => f.Height >= package.Height))
            {
                stored = floor.StorePackage(package, out placementPoint);

                // Create new floor
                if (stored && package.Stackable)
                    CreateNewFloor(floor.LevelHeight, placementPoint, package);

                // Done
                if (stored)
                {
                    Packages.Add(package);
                    break;
                }
            }

            return stored;
        }
        private bool IsPackageSameAsFloor(ref Package pack, ref Floor floor)
        {
            // Yeah...this is what I do now....

            bool result = false;

            if (pack.Length == floor.Width && pack.Width == floor.Length)
                return true;

            if (pack.Length == floor.Length && pack.Width == floor.Width)
                return true;

            return result;
        }
        private void CreateNewFloor(int startHeight, Point placementPoint, Package onPackage)
        {
            int newId = Floors.Max(f => f.Id) + 1;

            int newFloorHeight = startHeight + onPackage.Height;
            int availableHeight = Height - newFloorHeight;

            if (availableHeight > 0)
            {
                Floors.Add(new Floor(onPackage.Length, onPackage.Width, availableHeight, placementPoint, newFloorHeight, newId));
                SortFloors();
            }
        }
        private void SortFloors()
        {
            Floors = Floors.OrderByDescending(f => f.LevelHeight).ToList();
        }
        public void SetName(string name)
        {
            Name = name;
        }
        public Truck Clone()
        {
            return Create(Name, Length, Width, Height);
        }
    }

}
