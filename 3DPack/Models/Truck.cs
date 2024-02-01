

using System.Drawing;

namespace _3DPack.Models
{
    public class Truck
    {
        public string Name { get; private set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }
        public int Levels { get; set; }

        public List<Floor> Floors { get; set; }

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
        }

        public void InsertPackage(Package package)
        {
            SortFloors();

            List<Floor> newFloors = new List<Floor>();
            Point placementPoint = new Point();

            foreach (Floor floor in Floors)
            {
                bool stored = floor.StorePackage(package, out placementPoint);

                // Create new floor
                if (stored && package.Stackable)
                    CreateNewFloor(floor.LevelHeight, placementPoint, package);

                // Done
                if (stored)
                    break;
            }
        }

        private void CreateNewFloor(int startHeight, Point placementPoint, Package onPackage)
        {
            int newFloorHeight = startHeight + onPackage.Height;
            int availableHeight = Height - newFloorHeight;

            if (availableHeight > 0)
            {
                Floors.Add(new Floor(onPackage.Length, onPackage.Width, availableHeight, placementPoint, newFloorHeight));
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
    }

}
