using _3DPack.Models;
using System.Windows;

namespace PackGUI
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            //Truck truck = new Truck(240, 1360, 260);

            //Package rack = new Package(80, 400, 80);
            //Package square = new Package(80, 80, 80);

            //for (int i = 0; i < 100; i++)
            //{
            //    truck.Floors[0].StorePackage(square);
            //}

            Truck truck = new Truck(100, 1000, 260);

            Package p0 = new Package(40, 250, 80);
            Package p1 = new Package(40, 500, 80);
            Package p2 = new Package(30, 200, 80);

            truck.Floors[0].StorePackage(p0);
            truck.Floors[0].StorePackage(p1);
            truck.Floors[0].StorePackage(p2);

        }
    }
}