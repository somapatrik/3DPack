using System.Drawing;
using optimal2dx;

namespace _3DPack
{
    public class Truck
    {
        public string Name { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }
        public int Length { get; private set; }
        public List<Floor> Floors { get; private set; }
        public List<Package> Unpacked { get; private set; }
        public List<Package> Packed { get; private set; }
        public int UsedArea
        {
            get
            {
                return Floors.Sum(f => f.UsedArea);
            }
        }

        private TaskCompletionSource<bool> _finishedOpt;
        private Optimization2DX _optimization2DX;

        public static Truck Create(string name, int length, int width, int height)
        {
            var t = new Truck(length, width, height);
            t.SetName(name);
            return t;
        }

        public Truck(int length, int width, int height)
        {
            Name = "";
            Width = width;
            Height = height;
            Length = length;

            Floors = new List<Floor>()
            {
                new Floor(length, width, height, new Point(0,0), 0)
            };

            Packed = new List<Package>();
            Unpacked = new List<Package>();

            _optimization2DX = new Optimization2DX();
            _optimization2DX.OnFinish += Optimization2DX_OnFinish;

            _optimization2DX.BladeWidth = 0;
            _optimization2DX.RandomSeed = 1;
            _optimization2DX.OptimizationLevel = 50;
        }

        private void Optimization2DX_OnFinish()
        {
            int SheetIndex = 0;

            int top_x, top_y, bottom_x, bottom_y, thick;
            int repository_Index, repository_ID, demand_Index, demand_ID, rotated;

            double surf_covered;
            _optimization2DX.SurfaceCovered(SheetIndex, out surf_covered, out repository_Index, out repository_ID);
            
            int NumPieces;
            _optimization2DX.NumberOfUtilizedDemandPieces(SheetIndex, out NumPieces, out repository_Index, out repository_ID);
            for (int i = 0; i < NumPieces; i++)
            {
                _optimization2DX.GetUtilizedDemandPiece(SheetIndex, i, out top_x, out top_y, out bottom_x, out bottom_y, out rotated, out repository_Index, out demand_Index, out repository_ID, out demand_ID);
                StoreOptimizidedPackage(demand_ID, repository_ID, top_x, top_y, bottom_x, bottom_y);
            }

            _finishedOpt.SetResult(true);
        }

        public async void AreaOptimization(List<Package> toPack, int floorId = 0)
        {
            Unpacked = toPack.Select(p => p.Clone()).ToList();

            var floor = Floors.FirstOrDefault(f => f.Id == floorId);
          
            if (floor != null)
            {
                // Set floor repository
                _optimization2DX.NumberOfRepositoryPieces = 1;
                _optimization2DX.SetRepositoryPiece(0, floor.Length, floor.Width, 0, 0, 0, 0, floor.Id, 0, 0);
                _optimization2DX.NumberOfDemandPieces = Unpacked.Count;

                // Set packages
                int index = 0;
                var packagesToPack = Unpacked.Where(p => p.Height <= floor.Height);

                if (packagesToPack.Any())
                {
                    _optimization2DX.NumberOfDemandPieces = packagesToPack.Count();
                    foreach (var package in packagesToPack)
                    {
                        package.SetCutId(index);
                        _optimization2DX.SetDemandPiece(index, package.Length, package.Width, 1, package.Cut_Id, 0);
                        index++;
                    }

                    _finishedOpt = new TaskCompletionSource<bool>();
                    _optimization2DX.StartGuillotine();
                    await _finishedOpt.Task;
                }

                FinishFloor(ref floor);
           }
        }

        private void StoreOptimizidedPackage(int packageCutId, int floorId, int topX, int topY, int bottomX, int bottomY)
        {
            var package = Unpacked.FirstOrDefault(p=>p.Cut_Id == packageCutId);
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

                Unpacked.Remove(package);
                Packed.Add(package);
            }


        }

        private void FinishFloor(ref Floor floor)
        {
            floor.Full = true;

            var availableFloors = Floors.Where(f => f.Full == false);
            
            if (Unpacked.Any() && availableFloors.Any())
            {
                AreaOptimization(Unpacked, availableFloors.OrderByDescending(f => f.LevelHeight).First().Id);
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

                Packed.Add(winner.Package);
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
                    Packed.Add(package);
                    break;
                }
            }

            return stored;
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
        public List<Package> CopyUnpacked()
        {
            return Unpacked.Select(u=>u.Clone()).ToList();
        }
    }

}
