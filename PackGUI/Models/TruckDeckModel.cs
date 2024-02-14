using System.Drawing;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace PackGUI.Models
{
    public class TruckDeckModel
    {
        public ModelVisual3D VisualModel {  get; set; }

        public List<ModelVisual3D> PackageModels { get; set; }
        public GeometryModel3D GeometryModel { get; set; } 

        private MeshGeometry3D _geometry3D; 

        private int _deckThicknes = 10;

        public TruckDeckModel(Point origin, int length, int width, int height) 
        {
            _geometry3D = new MeshGeometry3D();
            PackageModels = new List<ModelVisual3D>();

            int backZ = origin.Y;
            int frontZ = origin.Y + width;

            int deckLevelY = 0;
            int deckBottomLevelY = deckLevelY - _deckThicknes;

            int leftSideX = origin.X;
            int rightSideX = origin.X + length;

            List<Point3D> vertices = new List<Point3D>()
            {
                // Back-side
                new Point3D(leftSideX, deckBottomLevelY, backZ),       // 0
                new Point3D(rightSideX, deckBottomLevelY, backZ),      // 1
                new Point3D(rightSideX, deckLevelY, backZ),            // 2
                new Point3D(leftSideX, deckLevelY, backZ),             // 3

                // Front-side
                new Point3D(leftSideX, deckBottomLevelY, frontZ),      // 4
                new Point3D(rightSideX, deckBottomLevelY, frontZ),     // 5
                new Point3D(rightSideX, deckLevelY, frontZ),           // 6
                new Point3D(leftSideX, deckLevelY, frontZ),            // 7

            };

            vertices.ForEach(_geometry3D.Positions.Add);

            // Back
            _geometry3D.TriangleIndices.Add(0);
            _geometry3D.TriangleIndices.Add(3);
            _geometry3D.TriangleIndices.Add(2);

            _geometry3D.TriangleIndices.Add(1);
            _geometry3D.TriangleIndices.Add(0);
            _geometry3D.TriangleIndices.Add(2);

            // Right
            _geometry3D.TriangleIndices.Add(1);
            _geometry3D.TriangleIndices.Add(2);
            _geometry3D.TriangleIndices.Add(6);

            _geometry3D.TriangleIndices.Add(5);
            _geometry3D.TriangleIndices.Add(1);
            _geometry3D.TriangleIndices.Add(6);

            // Left
            _geometry3D.TriangleIndices.Add(0);
            _geometry3D.TriangleIndices.Add(4);
            _geometry3D.TriangleIndices.Add(7);

            _geometry3D.TriangleIndices.Add(3);
            _geometry3D.TriangleIndices.Add(0);
            _geometry3D.TriangleIndices.Add(7);

            // Bottom
            _geometry3D.TriangleIndices.Add(0);
            _geometry3D.TriangleIndices.Add(1);
            _geometry3D.TriangleIndices.Add(4);

            _geometry3D.TriangleIndices.Add(1);
            _geometry3D.TriangleIndices.Add(5);
            _geometry3D.TriangleIndices.Add(4);

            // Top
            _geometry3D.TriangleIndices.Add(7);
            _geometry3D.TriangleIndices.Add(6);
            _geometry3D.TriangleIndices.Add(3);

            _geometry3D.TriangleIndices.Add(2);
            _geometry3D.TriangleIndices.Add(3);
            _geometry3D.TriangleIndices.Add(6);

            // Front
            _geometry3D.TriangleIndices.Add(4);
            _geometry3D.TriangleIndices.Add(5);
            _geometry3D.TriangleIndices.Add(7);

            _geometry3D.TriangleIndices.Add(5);
            _geometry3D.TriangleIndices.Add(6);
            _geometry3D.TriangleIndices.Add(7);

            SolidColorBrush materialBrush = new SolidColorBrush(Colors.Gray);
            DiffuseMaterial material = new DiffuseMaterial(materialBrush);

            GeometryModel = new GeometryModel3D(_geometry3D, material);
            VisualModel = new ModelVisual3D();
            VisualModel.Content = GeometryModel;
        }

        internal void AddPackage(Point packageOrigin, int levelHeight, int length, int width, int height)
        {
            MeshGeometry3D packageModel = new MeshGeometry3D();

            int backZ = packageOrigin.Y;
            int frontZ = packageOrigin.Y + width;

            int topY = levelHeight + height;
            int bottomY = levelHeight;

            int leftSideX = packageOrigin.X;
            int rightSideX = packageOrigin.X + length;

            List<Point3D> vertices = new List<Point3D>()
            {
                // Back-side
                new Point3D(leftSideX, bottomY, backZ),       // 0
                new Point3D(rightSideX, bottomY, backZ),      // 1
                new Point3D(rightSideX, topY, backZ),         // 2
                new Point3D(leftSideX, topY, backZ),          // 3

                // Front-side
                new Point3D(leftSideX, bottomY, frontZ),       // 4
                new Point3D(rightSideX, bottomY, frontZ),      // 5
                new Point3D(rightSideX, topY, frontZ),         // 6
                new Point3D(leftSideX, topY, frontZ),          // 7

            };

            vertices.ForEach(packageModel.Positions.Add);

            // Back
            packageModel.TriangleIndices.Add(0);
            packageModel.TriangleIndices.Add(3);
            packageModel.TriangleIndices.Add(2);

            packageModel.TriangleIndices.Add(1);
            packageModel.TriangleIndices.Add(0);
            packageModel.TriangleIndices.Add(2);

            // Right
            packageModel.TriangleIndices.Add(1);
            packageModel.TriangleIndices.Add(2);
            packageModel.TriangleIndices.Add(6);

            packageModel.TriangleIndices.Add(5);
            packageModel.TriangleIndices.Add(1);
            packageModel.TriangleIndices.Add(6);

            // Left
            packageModel.TriangleIndices.Add(0);
            packageModel.TriangleIndices.Add(4);
            packageModel.TriangleIndices.Add(7);

            packageModel.TriangleIndices.Add(3);
            packageModel.TriangleIndices.Add(0);
            packageModel.TriangleIndices.Add(7);

            // Bottom
            packageModel.TriangleIndices.Add(0);
            packageModel.TriangleIndices.Add(1);
            packageModel.TriangleIndices.Add(4);

            packageModel.TriangleIndices.Add(1);
            packageModel.TriangleIndices.Add(5);
            packageModel.TriangleIndices.Add(4);

            // Top
            packageModel.TriangleIndices.Add(7);
            packageModel.TriangleIndices.Add(6);
            packageModel.TriangleIndices.Add(3);

            packageModel.TriangleIndices.Add(2);
            packageModel.TriangleIndices.Add(3);
            packageModel.TriangleIndices.Add(6);

            // Front
            packageModel.TriangleIndices.Add(4);
            packageModel.TriangleIndices.Add(5);
            packageModel.TriangleIndices.Add(7);

            packageModel.TriangleIndices.Add(5);
            packageModel.TriangleIndices.Add(6);
            packageModel.TriangleIndices.Add(7);

            Random r = new Random();
            Brush brush = new SolidColorBrush(System.Windows.Media.Color.FromArgb(255,(byte)r.Next(1, 255), (byte)r.Next(1, 255), (byte)r.Next(1, 233)));

            //SolidColorBrush materialBrush = new SolidColorBrush(brush);
            DiffuseMaterial material = new DiffuseMaterial(brush);
            GeometryModel3D geometry = new GeometryModel3D(packageModel, material);

            PackageModels.Add(new ModelVisual3D() { Content = geometry });
        }

    }

}