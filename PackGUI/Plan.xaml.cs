using PackGUI.Models;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace PackGUI
{
    public partial class Plan : Window
    {

        PerspectiveCamera camera;
        AmbientLight ambientLight;

        private List<TruckDeckModel> _truckDeckModels;

        public Plan(List<TruckDeckModel> decks)
        {
            InitializeComponent();
            DataContext = this;        

            _truckDeckModels = decks;

            // Light
            Model3DGroup LightGroup = new Model3DGroup();
            AmbientLight myPointLight = new AmbientLight();
            myPointLight.Color = Colors.White;
            LightGroup.Children.Add(myPointLight);

            // Add light
            myViewport.Children.Add(new ModelVisual3D() { Content = LightGroup });

            // Add objects
            _truckDeckModels.ForEach(deck =>
            {
                myViewport.Children.Add(deck.ModelContent);
            });

            camera = new PerspectiveCamera();
            camera.Position = _truckDeckModels[0].CameraDefaultPosition; //new Point3D(500, 1000, 650);
            camera.LookDirection = _truckDeckModels[0].CameraDefaultLookAt;//new Vector3D(1, 0, 0);
            camera.UpDirection = new Vector3D(0, 1, 0);
            camera.FieldOfView = 60;

            myViewport.Camera = camera;

        }

        private void Grid_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == Key.NumPad8)
            {
                Move(400);
            }
            else if (e.Key == Key.NumPad2)
            {
                Move(-400);
            }
            else if (e.Key == Key.NumPad4)
            {
                RotateHorizontal(-5);
            }
            else if (e.Key == Key.NumPad6)
            {
                RotateHorizontal(5);
            }

        }

        private void RotateHorizontal(int angle)
        {
            Point3D objectPosition = _truckDeckModels[0].CenterPoint;
            var rotationAngle = angle * (Math.PI / 180);

            double newX = objectPosition.X + (camera.Position.X - objectPosition.X) * Math.Cos(rotationAngle) - (camera.Position.Z - objectPosition.Z) * Math.Sin(rotationAngle);
            double newZ = objectPosition.Z + (camera.Position.X - objectPosition.X) * Math.Sin(rotationAngle) + (camera.Position.Z - objectPosition.Z) * Math.Cos(rotationAngle);
            double newY = camera.Position.Y;

            camera.Position = new Point3D(newX, newY, newZ);
            camera.LookDirection = new Vector3D(objectPosition.X - newX, objectPosition.Y - newY, objectPosition.Z - newZ);
            camera.UpDirection = new Vector3D(0, 1, 0);
        }

        public void RotateVertical(int angle)
        {
            Point3D objectPosition = _truckDeckModels[0].CenterPoint;
            var rotationAngle = angle * (Math.PI / 180);

            //Point3D currentCameraPosition = camera.Position;

            double newX = objectPosition.X + (camera.Position.X - objectPosition.X) * Math.Cos(rotationAngle) - (camera.Position.Z - objectPosition.Z) * Math.Sin(rotationAngle);
            double newY = objectPosition.Y + (camera.Position.Y - objectPosition.Y) * Math.Cos(rotationAngle) + (camera.Position.Z - objectPosition.Z) * Math.Sin(rotationAngle);
            double newZ = objectPosition.Z - (camera.Position.Y - objectPosition.Y) * Math.Sin(rotationAngle) + (camera.Position.Z - objectPosition.Z) * Math.Cos(rotationAngle);

            camera.Position = new Point3D(camera.Position.X, newY, camera.Position.Z);
            camera.LookDirection = new Vector3D(objectPosition.X - camera.Position.X, objectPosition.Y - newY, objectPosition.Z - newZ);
            camera.UpDirection = new Vector3D(0, 1, 0);
        }

        public void Move(double d)
        {
            double u = 0.05;
           // PerspectiveCamera camera = (PerspectiveCamera)Viewport3D.Camera;
            Vector3D lookDirection = camera.LookDirection;
            Point3D position = camera.Position;

            lookDirection.Normalize();
            position = position + u * lookDirection * d;

            camera.Position = position;
        }

        public void Rotate(double d)
        {
            double u = 0.05;
            double angleD = u * d;
            //PerspectiveCamera camera = (PerspectiveCamera)Viewport3D.Camera;
            Vector3D lookDirection = camera.LookDirection;

            var m = new Matrix3D();
            m.Rotate(new Quaternion(camera.UpDirection, -angleD)); // Rotate about the camera's up direction to look left/right
            camera.LookDirection = m.Transform(camera.LookDirection);
        }

        private void oldrot()
        {
            //double u = 0.05;
            //double angleD = u * d;
            ////PerspectiveCamera camera = (PerspectiveCamera)Viewport3D.Camera;
            //Vector3D lookDirection = camera.LookDirection;

            //// Cross Product gets a vector that is perpendicular to the passed in vectors (order does matter, reverse the order and the vector will point in the reverse direction)
            //var cp = Vector3D.CrossProduct(camera.UpDirection, lookDirection);
            //cp.Normalize();

            //var m = new Matrix3D();
            //m.Rotate(new Quaternion(cp, -angleD)); // Rotate about the vector from the cross product
            //camera.LookDirection = m.Transform(camera.LookDirection);
        }

        private void Window_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
            {
                Move(500);
            }
            else if (e.Delta < 0)
            {
                Move(-500);
            }
        }

        private void Window_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            
        }
    }
}
