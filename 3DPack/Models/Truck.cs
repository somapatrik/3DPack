﻿using System.Drawing;

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
