using System.Drawing;

namespace _3DPack.Models
{
    public class Floor
    {
        public int Length { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }

        public Point OriginPoint { get; private set; }
        public int LevelHeight { get; private set; }

        List<Point> BorderPoints = new List<Point>();
        List<Package> Packages = new List<Package>();
        List<BlockedArea> BlockedAreas = new List<BlockedArea>();

        Rectangle FloorArea = new Rectangle();
        List<Point> StartingPoints = new List<Point>();

        public Floor(int length, int width, int height, Point originPoint, int levelHeight)
        {
            Height = height;
            Width = width;
            Length = length;

            DimensionsToPoints(length, width, height);

            OriginPoint = originPoint;
            LevelHeight = levelHeight;
        }

        private void DimensionsToPoints(int length, int width, int height)
        {
            Point origin = new Point(0, 0);
            Point topRight = new Point(length, 0);

            Point leftBottom = new Point(0,width);
            Point rightBottom = new Point(length,width);

            FloorArea.X = origin.X;
            FloorArea.Y = origin.Y;
            FloorArea.Width = length;
            FloorArea.Height = width;

            BorderPoints = new List<Point>() { origin, topRight, leftBottom, rightBottom };
            StartingPoints.Add(new Point(origin.X, origin.Y));
        }

        public bool StorePackage(Package package, out Point PlacementPoint)
        {
            bool CanPlace = false;
            PlacementPoint = new Point();

            if (package.Height > Height)
                return false;
            
            foreach (Point point in StartingPoints)
            {
                PlacementPoint = new Point(point.X, point.Y);

                //CanPlace = CanPlacePackage(package, PlacementPoint);
                CanPlace = TryAllRotations(package, PlacementPoint);

                if (CanPlace)
                    break;
            }

            if (CanPlace)
                PlacePackage(package,PlacementPoint);

            return CanPlace;
        }

        private bool TryAllRotations(Package package, Point PlacementPoint)
        {
            if (package.Rotation == RotationType.Equilateral)
                return CanPlacePackage(package, PlacementPoint);

            if (package.Rotation != RotationType.Horizontal)
                package.RotateToBeHorizontal();
            
            if (CanPlacePackage(package, PlacementPoint))
                return true;

            if (package.Rotation != RotationType.Vertical)
                package.RotateToBeVertical();

            if (CanPlacePackage(package, PlacementPoint))
                return true;

            return false;
        }

        private void PlacePackage(Package package, Point PlacementPoint)
        {
            AddBlockedArea(package, PlacementPoint);
            AddPackage(package);
            RemoveStartingPoint(PlacementPoint);
            SortStartingPoints();
        }

        private bool CanPlacePackage(Package package, Point point)
        {
            bool IsInside = IsInsideFloor(package, point);
            bool IsCollidingBlockedArea = IsCollisionWithBlockedArea(package, point);

            return IsInside && !IsCollidingBlockedArea;
        }

        private void SortStartingPoints()
        {
            StartingPoints = StartingPoints.OrderBy(p=>p.Y).ThenBy(p=>p.X).ToList();
        }

        private void RemoveStartingPoint(Point point)
        {
            StartingPoints.RemoveAll(p=>p.X == point.X && p.Y==point.Y);
        }

        private void AddPackage(Package package)
        {
            Packages.Add(package);
        }

        private void AddBlockedArea(Package package, Point placementPoint)
        {
            BlockedArea blocked = new BlockedArea(placementPoint, package.Length, package.Width);
            BlockedAreas.Add(blocked);

            // Starting points should be NEXT to a blocked area
            // NOT USED DUE TO THE RECTANGLE CLASS FUNCTIONS

            Point topRight = blocked.TopRight;
            // topRight.X += 1;

            Point bottomLeft = blocked.BottomLeft;
            // bottomLeft.Y += 1;

            StartingPoints.Add(topRight);
            StartingPoints.Add(bottomLeft);
        }

        private bool IsInsideFloor(Package package, Point point)
        {
            Rectangle floor = new Rectangle(FloorArea.X, FloorArea.Y, FloorArea.Width, FloorArea.Height);
            Rectangle packageFloor = PackageToArea(package, point);

            return floor.Contains(packageFloor);
        }

        private bool IsCollisionWithBlockedArea(Package package, Point point)
        {
            bool IsCollision = false;

            foreach (BlockedArea blockedArea in BlockedAreas)
            {
                if (blockedArea.IsPackageColliding(package, point))
                {
                    IsCollision = true;
                    break;
                }
            }
            return IsCollision;
        }

        private Rectangle PackageToArea(Package package, Point point)
        {
            return new Rectangle(point.X, point.Y, package.Length, package.Width);
        }
    }
}
