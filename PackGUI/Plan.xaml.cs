using _3DPack;
using PackGUI.Models;
using PackGUI.ViewModels;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace PackGUI
{
    public partial class Plan : Window
    {

        PerspectiveCamera camera;
        AmbientLight ambientLight;

        public Plan(List<TruckDeckModel> decks)
        {
            InitializeComponent();
            DataContext = this;

            camera = new PerspectiveCamera();
            camera.Position = new Point3D(240, 200, 1600);
            camera.LookDirection = new Vector3D(0, -.5, -1);
            camera.UpDirection = new Vector3D(0, 1, 0);
            camera.FieldOfView = 60;

            myViewport.Camera = camera;

            AmbientLight myPointLight = new AmbientLight();
            myPointLight.Color = Colors.White;
            //myPointLight.Position = new Point3D(0, 10, 0);
            
            

            Model3DGroup group = new Model3DGroup();

            group.Children.Add(myPointLight);
            ModelVisual3D visual = new ModelVisual3D();
            visual.Content = group;
            myViewport.Children.Add(visual);



            decks.Select(d=>d.VisualModel).ToList().ForEach(myViewport.Children.Add);
        }

        private void Grid_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == Key.D)
            {
                Rotate(100);
            }
            else if (e.Key == Key.A)
            {
                Rotate(-100);
            }
            else if (e.Key == Key.S)
            {
                Move(-200);
            }
            else if (e.Key == Key.W)
            {
                Move(200);
            }
            else if (e.Key == Key.NumPad8)
            {
                RotateVertical(100);
            }
            else if (e.Key == Key.NumPad2)
            {
                RotateVertical(-100);
            }

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

        public void RotateVertical(double d)
        {
            double u = 0.05;
            double angleD = u * d;
            //PerspectiveCamera camera = (PerspectiveCamera)Viewport3D.Camera;
            Vector3D lookDirection = camera.LookDirection;

            // Cross Product gets a vector that is perpendicular to the passed in vectors (order does matter, reverse the order and the vector will point in the reverse direction)
            var cp = Vector3D.CrossProduct(camera.UpDirection, lookDirection);
            cp.Normalize();

            var m = new Matrix3D();
            m.Rotate(new Quaternion(cp, -angleD)); // Rotate about the vector from the cross product
            camera.LookDirection = m.Transform(camera.LookDirection);
        }

    }
}
