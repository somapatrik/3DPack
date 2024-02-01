using _3DPack.Models;
using System.Windows;

namespace PackGUI
{

    public partial class MainWindow : Window
    {
        List<Package> availablePackages = new List<Package>();
        List<Truck> availableTrucks = new List<Truck>();

        public MainWindow()
        {
            availablePackages.AddRange(
            [
                Package.Create("Rack", 80, 400, 80, true),
                Package.Create("Rack UPS", 100, 200, 125),
                Package.Create("Blue box for IS doors till 2.4m", 120, 240, 110),
                Package.Create("Blue box for IS doors over 2.4m", 120, 270, 110),
                Package.Create("Palette - UK", 120, 320, 120),
                Package.Create("Palette Danemark (tour Dvořák)", 120, 400, 120),
                Package.Create("Palette Danemark (tour Dcs)", 120, 350, 120),
                Package.Create("Palette - Heytens, Decogroup", 120, 270, 145),
                Package.Create("Trolley UPS (boxes over 200 cm)", 120, 270, 124)
            ]);

            availableTrucks.AddRange(
            [
                Truck.Create("Van", 210, 380, 150),
                Truck.Create("Truck", 240, 1360, 260)
            ]);

            Packager packager = new Packager();
            packager.Optimize(availableTrucks, availablePackages);
            
        }
    }
}