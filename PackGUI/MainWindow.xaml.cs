using _3DPack;
using System.Windows;

namespace PackGUI
{

    public partial class MainWindow : Window
    {
        public List<Package> availablePackages = new List<Package>();
        List<Truck> availableTrucks = new List<Truck>();

        List<Package> selectedPackaged = new List<Package>();

        Packager Packager = new Packager();

        public MainWindow()
        {
            InitializeComponent();
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

            allPackages.ItemsSource = availablePackages;
            //selectedPacks.ItemsSource = selectedPackaged;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            selectedPacks.Items.Add(((Package)allPackages.SelectedItem).Clone());
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            selectedPacks.Items.Remove((Package)selectedPacks.SelectedItem);
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            List<Package> packages = new List<Package>();
            foreach (var pack in selectedPacks.Items)
                packages.Add(((Package)pack).Clone());
            
            Packager.Setup(availableTrucks, packages);
            btnRun.IsEnabled = true;
        }

        private async void Button_Click_3(object sender, RoutedEventArgs e)
        {
            Packager.Pack();

            btnRun.IsEnabled = false;
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            selectedPacks.Items.Clear();
            foreach (var item in availablePackages)
            {
                selectedPacks.Items.Add(item.Clone());
            }
        }
    }
}