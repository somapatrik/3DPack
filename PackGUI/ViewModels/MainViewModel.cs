using _3DPack;
using PackGUI.Models;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Windows.Input;

namespace PackGUI.ViewModels
{
    internal class MainViewModel : PrimeViewModel
    {
        private PackResult _result;
        private Package _selectedPackage;
        private ObservableCollection<Package> _selectedPackages;

        private List<Package> _availablePackages = new List<Package>()
        {
            Package.Create("Rack", 80, 400, 80, true),
            Package.Create("Rack UPS", 100, 200, 125),
            Package.Create("Blue box for IS doors till 2.4m", 120, 240, 110),
            Package.Create("Blue box for IS doors over 2.4m", 120, 270, 110),
            Package.Create("Palette - UK", 120, 320, 120),
            Package.Create("Palette Danemark (tour Dvořák)", 120, 400, 120),
            Package.Create("Palette Danemark (tour Dcs)", 120, 350, 120),
            Package.Create("Palette - Heytens, Decogroup", 120, 270, 145),
            Package.Create("Trolley UPS (boxes over 200 cm)", 120, 270, 124)
        };

        private List<Truck> _availableTrucks = new List<Truck>()
        {
            Truck.Create("Van", 210, 380, 150),
            Truck.Create("Truck", 240, 1360, 260)
        };
                
        public List<Package> availablePackages => _availablePackages;
        public List<Truck> availableTrucks => _availableTrucks;

        public Package selectedPackage { get => _selectedPackage; set => SetProperty(ref _selectedPackage, value); }
        public ObservableCollection<Package> selectedPackages { get => _selectedPackages; set => SetProperty(ref _selectedPackages, value); }
        public PackResult result { get => _result; set => SetProperty(ref _result, value); }


        public ICommand Run { get; private set; }
        public ICommand Insert { get; private set; }
        public ICommand InsertAll { get; private set; }
        public ICommand Remove { get; private set; }
        public ICommand SelectResult { get; private set; }


        Packager Packager = new Packager();

        public MainViewModel() 
        {
            Run = new RelayCommand(RunExecute);

            Insert = new RelayCommand(InsertExecute);
            InsertAll = new RelayCommand(InsertAllExecute);
            Remove = new RelayCommand(RemoveExecute);
            SelectResult = new RelayCommand(SelectResultHandler);

            InsertAllExecute(null);
            RunExecute(null);
        }

        private void SelectResultHandler(object obj)
        {
            //var plan = new Plan(selectedResult);
           // plan.Show();
        }

        private void RemoveExecute(object obj)
        {
            selectedPackages.Clear();
        }

        private void InsertAllExecute(object obj)
        {
            selectedPackages = new ObservableCollection<Package>();
            availablePackages.ForEach(a=>selectedPackages.Add(a.Clone()));
        }

        private void InsertExecute(object obj)
        {
            if (selectedPackages == null)
                selectedPackages = new ObservableCollection<Package>();

            selectedPackages.Add(selectedPackage.Clone());
        }

        private async void RunExecute(object obj)
        {
            Packager.Setup(
                availableTrucks.Select(s => s.Clone()).ToList(),
                selectedPackages.Select(s => s.Clone()).ToList()
                );

            List<TruckDeckModel> decks = new List<TruckDeckModel>();
            var trucks = await Packager.Pack();

            trucks.ForEach(truck => 
            {
                var baseFloor = truck.Floors.First(f=>f.LevelHeight == 0);
                var deck = new TruckDeckModel(baseFloor.OriginPoint, truck.Length, truck.Width, truck.Height);

                truck.Floors.ForEach(floor =>
                {
                    Point floorOrigin = floor.OriginPoint;
                    //int floorOriginHeight = floor.LevelHeight;

                    floor.BlockedAreas.ForEach(area => 
                    {
                        var package = floor.Packages.FirstOrDefault(p=>p.Id == area.CockBlockedByPackage);
                        if (package != null)
                        {
                            Point packageOrigin = new Point(floorOrigin.X + area.Area.X, floorOrigin.Y + area.Area.Y);
                            deck.AddPackage(packageOrigin, floor.LevelHeight,package.Length, package.Width, package.Height);
                        }
                    });
                    
                });

                decks.Add(deck);

            });

            Plan plan = new Plan(decks);
            plan.Show();
        }
    }
}
