using _3DPack.Models;
using System.Windows;

namespace PackGUI
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            Truck truck = new Truck(240, 1360, 260);

            Package package = new Package(80, 400, 80);
            Package package2 = new Package(240, 240, 80);

            truck.Floors[0].StorePackage(package);
            truck.Floors[0].StorePackage(package2);
        }
    }
}