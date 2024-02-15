using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace PackGUI.Models
{
    public class TruckDeckModel
    {
        // Can be inserted into ViewPort3D
        public ModelVisual3D ModelContent => new ModelVisual3D() { Content = ModelGroup };
        
        // Conatins all models
        public Model3DGroup ModelGroup { get; set; }

        // Center point
        public Vector3D LookAtPoint 
        {
            get
            {
                return new Vector3D
                  (
                    ModelGroup.Bounds.SizeX / 2 + ModelGroup.Bounds.X,
                    ModelGroup.Bounds.SizeY / 2 + ModelGroup.Bounds.Y,
                    ModelGroup.Bounds.SizeZ / 2 + ModelGroup.Bounds.Z
                );
                
            }
        }

        private int _deckThicknes = 10;
        
        public TruckDeckModel(int originX, int originY, int length, int width, int height) 
        {
            ModelGroup = new Model3DGroup();

            int backZ = originY;
            int frontZ = originY + width;

            int deckLevelY = 0;
            int deckBottomLevelY = deckLevelY - _deckThicknes;

            int leftSideX = originX;
            int rightSideX = originX + length;

            MeshGeometry3D _geometry3D = GetRectangleMesh(backZ, frontZ, deckLevelY, deckBottomLevelY, leftSideX, rightSideX);

            SolidColorBrush materialBrush = new SolidColorBrush(Colors.Gray);
            DiffuseMaterial material = new DiffuseMaterial(materialBrush);

            GeometryModel3D GeometryModel = new GeometryModel3D(_geometry3D, material);
            ModelGroup.Children.Add(GeometryModel);

        }

        internal void AddPackage(int packageOriginX, int packageOriginY, int levelHeight, int length, int width, int height)
        {
            int backZ = packageOriginY;
            int frontZ = packageOriginY + width;

            int topY = levelHeight + height;
            int bottomY = levelHeight;

            int leftSideX = packageOriginX;
            int rightSideX = packageOriginX + length;

            MeshGeometry3D packageModel = GetRectangleMesh(backZ, frontZ, topY, bottomY, leftSideX, rightSideX);

            Random r = new Random();
            Brush brush = new SolidColorBrush(System.Windows.Media.Color.FromArgb(255,(byte)r.Next(1, 255), (byte)r.Next(1, 255), (byte)r.Next(1, 233)));

            DiffuseMaterial material = new DiffuseMaterial(brush);
            GeometryModel3D geometry = new GeometryModel3D(packageModel, material);

            ModelGroup.Children.Add(geometry);
        }

        private MeshGeometry3D GetRectangleMesh(int backZ, int frontZ, int topY, int bottomY, int leftX, int rightX)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();

            List<Point3D> vertices = new List<Point3D>()
            {
                // Back-side
                new Point3D(leftX, bottomY, backZ),       // 0
                new Point3D(rightX, bottomY, backZ),      // 1
                new Point3D(rightX, topY, backZ),         // 2
                new Point3D(leftX, topY, backZ),          // 3

                // Front-side
                new Point3D(leftX, bottomY, frontZ),       // 4
                new Point3D(rightX, bottomY, frontZ),      // 5
                new Point3D(rightX, topY, frontZ),         // 6
                new Point3D(leftX, topY, frontZ),          // 7

            };

            vertices.ForEach(mesh.Positions.Add);
            /*
            // Back
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(3);
            mesh.TriangleIndices.Add(2);

            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(2);

            // Right
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(2);
            mesh.TriangleIndices.Add(6);

            mesh.TriangleIndices.Add(5);
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(6);

            // Left
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(4);
            mesh.TriangleIndices.Add(7);

            mesh.TriangleIndices.Add(3);
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(7);

            // Bottom
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(4);

            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(5);
            mesh.TriangleIndices.Add(4);

            // Top
            mesh.TriangleIndices.Add(7);
            mesh.TriangleIndices.Add(6);
            mesh.TriangleIndices.Add(3);

            mesh.TriangleIndices.Add(2);
            mesh.TriangleIndices.Add(3);
            mesh.TriangleIndices.Add(6);

            // Front
            mesh.TriangleIndices.Add(4);
            mesh.TriangleIndices.Add(5);
            mesh.TriangleIndices.Add(7);

            mesh.TriangleIndices.Add(5);
            mesh.TriangleIndices.Add(6);
            mesh.TriangleIndices.Add(7);
            */
            List<int> indices = new List<int>()
            {
                        0, 3, 2,
                        1, 0, 2,
                        // Right
                        1, 2, 6,
                        5, 1, 6,
                        // Left
                        0, 4, 7,
                        3, 0, 7,
                        // Bottom
                        0, 1, 4,
                        1, 5, 4,
                        // Top
                        7, 6, 3,
                        2, 3, 6,
                        // Front
                        4, 5, 7,
                        5, 6, 7
            };

            indices.ForEach(mesh.TriangleIndices.Add);

            return mesh;
        }


    }

}