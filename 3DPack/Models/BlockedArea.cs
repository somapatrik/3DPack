﻿using System.Drawing;

namespace _3DPack.Models
{
    internal class BlockedArea
    {
        public Rectangle Area { get; }
        
        public Point TopRight { get; }
        public Point TopLeft { get; }
        public Point BottomRight { get; }
        public Point BottomLeft { get; }

        public BlockedArea(Point startingPoint,int length, int width) 
        {
            Area = new Rectangle(startingPoint.X, startingPoint.Y, length, width);

            TopLeft = new Point(startingPoint.X,startingPoint.Y);
            TopRight = new Point(startingPoint.X + length, startingPoint.Y);
            BottomLeft = new Point(startingPoint.X,startingPoint.Y + width);
            BottomRight = new Point(startingPoint.X + length, startingPoint.Y + width);
        }

        public bool IsPackageColliding(Package package, Point fromPoint)
        {
            var packageFloor = new Rectangle(fromPoint.X, fromPoint.Y, package.Length, package.Width);
            return Area.IntersectsWith(packageFloor);
        }
    }
}
