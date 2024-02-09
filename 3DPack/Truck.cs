using System.Drawing;
using optimal2dx;
using static System.Net.Mime.MediaTypeNames;

namespace _3DPack
{
    public class Truck
    {
        Optimization2DX optimization2DX = new Optimization2DX();

        public string Name { get; private set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }
        public List<Floor> Floors { get; set; }

        public List<Package> Packages { get; private set; }

        public int UsedArea
        {
            get
            {
                return Floors.Sum(f => f.UsedArea);
            }
        }

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
        }

        public void AreaOptimization(List<Package> packages)
        {
            //foreach (var floor in Floors.OrderByDescending(f=>f.LevelHeight))
            //{
            
            optimization2DX.NumberOfRepositoryPieces = 1;
            optimization2DX.SetRepositoryPiece(0, Floors[0].Length, Floors[0].Width, 0, 0, 0, 0, 0, 0, 0);
            optimization2DX.OptimizationLevel = 50;

            optimization2DX.NumberOfDemandPieces = packages.Count;
            int index = 0;
            foreach (var package in packages.Where(p=>p.Height <= Floors[0].Height))
            {
                optimization2DX.SetDemandPiece(index, package.Length, package.Width, 1, index, 0);
                index++;
            }

            optimization2DX.OnFinish += Optimization2DX_OnFinish;

            optimization2DX.BladeWidth = 0;
            optimization2DX.RandomSeed = 1;
            optimization2DX.StartGuillotine();

            


            //}
        }

        private void Optimization2DX_OnProgress()
        {
           // throw new NotImplementedException();
        }

        private void Optimization2DX_OnFinish()
        {
            int SheetIndex = 0; // this is the first sheet;

            int top_x, top_y, bottom_x, bottom_y, thick;
            int repository_Index, repository_ID, demand_Index, demand_ID, rotated;

            int NumPieces;
            optimization2DX.NumberOfUtilizedDemandPieces(SheetIndex, out NumPieces, out repository_Index, out repository_ID);
            for (int i = 0; i < NumPieces; i++)
            {
                optimization2DX.GetUtilizedDemandPiece(SheetIndex, i, out top_x, out top_y, out bottom_x, out bottom_y, out rotated, out repository_Index, out demand_Index, out repository_ID, out demand_ID);
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

        private void CreateNewFloor(int startHeight, Point placementPoint, Package onPackage)
        {
            int newFloorHeight = startHeight + onPackage.Height;
            int availableHeight = Height - newFloorHeight;

            if (availableHeight > 0)
            {
                Floors.Add(new Floor(onPackage.Length, onPackage.Width, availableHeight, placementPoint, newFloorHeight));
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
