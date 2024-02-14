using System.Drawing;

namespace _3DPack
{
    public class Floor
    {
        public int Id { get; private set; }
        public int Length { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }
        public int Area { get; private set; }
        public int AvailableArea { get; private set; }
        public int UsedArea { get; private set; }
        public bool Full { get; set; }
        public Point OriginPoint { get; private set; }
        public int LevelHeight { get; private set; }

        public List<Package> Packages = new List<Package>();

        public List<BlockedArea> BlockedAreas = new List<BlockedArea>();

        Rectangle FloorArea = new Rectangle();
        List<Point> StartingPoints = new List<Point>();


        public Floor(int length, int width, int height, Point originPoint, int levelHeight, int id = 0)
        {
            Id = id;
            Height = height;
            Width = width;
            Length = length;

            Area = Length * Width;
            AvailableArea = Area;

            OriginPoint = originPoint;
            DimensionsToPoints(length, width);

            LevelHeight = levelHeight;
        }

        private void DimensionsToPoints(int length, int width)
        {
            FloorArea.X = OriginPoint.X;
            FloorArea.Y = OriginPoint.Y;
            FloorArea.Width = length;
            FloorArea.Height = width;

            StartingPoints.Add(new Point(OriginPoint.X, OriginPoint.Y));
        }

        /// <summary>
        /// Will try to place a package if there is place for it. Rotation will be also tested.
        /// </summary>
        public bool StorePackage(Package package, out Point PlacementPoint)
        {
            bool CanPlace = false;
            PlacementPoint = new Point();

            if (package.Height > Height)
                return false;

            foreach (Point point in StartingPoints)
            {
                PlacementPoint = new Point(point.X, point.Y);

                CanPlace = TryAllRotations(package, PlacementPoint);

                if (CanPlace)
                    break;
            }

            if (CanPlace)
                PlacePackage(package, PlacementPoint);

            return CanPlace;
        }

        /// <summary>
        /// Will try to place package and return some data about it
        /// </summary>
        public bool CheckPackagePlacement(Package package, out Point PlacementPoint, out int ldmRemain)
        {
            bool CanPlace = false;
            PlacementPoint = new Point();
            ldmRemain = 0;

            if (package.Height > Height)
                return false;

            foreach (Point point in StartingPoints)
            {
                PlacementPoint = new Point(point.X, point.Y);
                ldmRemain = 0;

                CanPlace = TryAllRotations(package, PlacementPoint);

                if (CanPlace)
                {
                    AnalyzePlacement(package, PlacementPoint, out ldmRemain);
                    break;
                }

            }

            return CanPlace;
        }

        /// <summary>
        /// Will place a package without any checks
        /// </summary>
        public void StorePackage(Package package, Point placementPoint)
        {
            PlacePackage(package, new Point(placementPoint.X, placementPoint.Y));
        }

        private void AnalyzePlacement(Package package, Point PlacementPoint, out int ldmRemain)
        {
            BlockedArea potencionalArea = new BlockedArea(PlacementPoint, package.Length, package.Width, package.Id);
            int actualMaxY = StartingPoints.Max(s => s.Y);

            actualMaxY = potencionalArea.BottomLeft.Y > actualMaxY ? potencionalArea.BottomLeft.Y : actualMaxY;

            ldmRemain = FloorArea.Y + FloorArea.Height - actualMaxY;
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
            SubtrackArea(package);
            AddUsedArea(package);
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

        private void SubtrackArea(Package package)
        {
            AvailableArea -= package.BaseArea;
        }

        private void AddUsedArea(Package package)
        {
            UsedArea += package.BaseArea;
        }

        private void SortStartingPoints()
        {
            StartingPoints = StartingPoints.OrderBy(p => p.Y).ThenBy(p => p.X).ToList();
        }

        private void RemoveStartingPoint(Point point)
        {
            StartingPoints.RemoveAll(p => p.X == point.X && p.Y == point.Y);
        }

        private void AddPackage(Package package)
        {
            Packages.Add(package);
        }

        private void AddBlockedArea(Package package, Point placementPoint)
        {
            BlockedArea blocked = new BlockedArea(placementPoint, package.Length, package.Width, package.Id);
            BlockedAreas.Add(blocked);

            Point topRight = blocked.TopRight;
            Point bottomLeft = blocked.BottomLeft;

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
