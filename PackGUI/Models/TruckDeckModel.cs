using System.Drawing;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace PackGUI.Models
{
    public class TruckDeckModel
    {
        public ModelVisual3D VisualModel {  get; set; }
        public GeometryModel3D GeometryModel { get; set; } 

        private MeshGeometry3D _geometry3D; 

        private int _deckThicknes = 10;

        public TruckDeckModel(Point origin, int length, int width, int height) 
        {
            _geometry3D = new MeshGeometry3D();

            List<Point3D> vertices = new List<Point3D>()
            {
                // Back-side
                new Point3D(origin.X, -_deckThicknes, origin.Y),               // 0
                new Point3D(origin.X + length, -_deckThicknes, origin.Y),      // 1
                new Point3D(origin.X + length, 0, origin.Y),                   // 2
                new Point3D(origin.X, 0, origin.Y),                            // 3

                // Front-side
                new Point3D(origin.X, -_deckThicknes, origin.Y + width),               // 4
                new Point3D(origin.X + length, -_deckThicknes, origin.Y + width),      // 5
                new Point3D(origin.X + length, 0, origin.Y + width),                   // 6
                new Point3D(origin.X, 0, origin.Y + width),                            // 7

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

            //for (int i = 0; i < vertices.Count; i++)
            //{
            //    Point3D vertex = vertices[i];

            //    // Normály pro každý vrchol
            //    Vector3D normal = CalculateVertexNormal(_geometry3D, vertex);
            //    normal.Normalize(); // Normalizace na jednotkovou délku

            //    // Přidání normály pro každý vrchol
            //    _geometry3D.Normals.Add(normal);
            //}


            SolidColorBrush materialBrush = new SolidColorBrush(Colors.Green);
            DiffuseMaterial material = new DiffuseMaterial(materialBrush);

            GeometryModel = new GeometryModel3D(_geometry3D, material);
            VisualModel = new ModelVisual3D();
            VisualModel.Content = GeometryModel;
        }

        // Metoda pro výpočet normály vrcholu na základě průměru normál přilehlých stěn
        private Vector3D CalculateVertexNormal(MeshGeometry3D meshGeometry, Point3D vertex)
        {
            Vector3D normalSum = new Vector3D();
            int faceCount = 0;

            for (int i = 0; i < meshGeometry.TriangleIndices.Count; i += 3)
            {
                int index1 = meshGeometry.TriangleIndices[i];
                int index2 = meshGeometry.TriangleIndices[i + 1];
                int index3 = meshGeometry.TriangleIndices[i + 2];

                if (meshGeometry.Positions[index1] == vertex ||
                    meshGeometry.Positions[index2] == vertex ||
                    meshGeometry.Positions[index3] == vertex)
                {
                    Vector3D side1 = meshGeometry.Positions[index2] - meshGeometry.Positions[index1];
                    Vector3D side2 = meshGeometry.Positions[index3] - meshGeometry.Positions[index1];
                    Vector3D faceNormal = Vector3D.CrossProduct(side1, side2);
                    faceNormal.Normalize();

                    normalSum += faceNormal;
                    faceCount++;
                }
            }

            return normalSum / faceCount;
        }

    }

}