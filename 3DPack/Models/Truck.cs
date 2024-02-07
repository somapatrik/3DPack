using System.Drawing;

namespace _3DPack.Models
{
    public class Truck
    {
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

        /// <summary>
        /// Tries to place every package. 
        /// </summary>
        public void StorePackages(List<Package> packages)
        {
            List<PlacementResult> PotentionalPacking = new List<PlacementResult>();

            foreach (Package pack in packages)
            {
                foreach (Floor floor in Floors.Where(f=>f.Height >= pack.Height))
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

            var winner = PotentionalPacking.OrderByDescending(p=>p.RemainingLDM).FirstOrDefault();

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
        /// Tries to place package to truck
        /// </summary>
        public bool InsertPackage(Package package)
        {
            List<Floor> newFloors = new List<Floor>();
            Point placementPoint = new Point();

            bool stored = false;

            foreach (Floor floor in Floors.Where(f=>f.Height >= package.Height))
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
