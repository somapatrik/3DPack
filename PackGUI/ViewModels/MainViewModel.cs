
using _3DPack;
using System.Collections.ObjectModel;
using System.Windows.Input;

namespace PackGUI.ViewModels
{
    internal class MainViewModel : PrimeViewModel
    {
        private Package _selectedPackage;
        private ObservableCollection<Package> _selectedPackages;
        private ObservableCollection<Truck> _results;

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

        public ObservableCollection<Package> selectedPackages {  get => _selectedPackages; set => SetProperty(ref _selectedPackages, value); }
        public ObservableCollection<Truck> results { get => _results; set => SetProperty(ref _results, value); }

        public ICommand SetupTest { get; private set; }
        public ICommand Run { get; private set; }
        public ICommand Insert { get; private set; }
        public ICommand InsertAll { get; private set; }
        public ICommand Remove { get; private set; }


        Packager Packager = new Packager();

        public MainViewModel() 
        {
            SetupTest = new RelayCommand(SetupTestExecute);
            Run = new RelayCommand(RunExecute);

            Insert = new RelayCommand(InsertExecute);
            InsertAll = new RelayCommand(InsertAllExecute);
            Remove = new RelayCommand(RemoveExecute);
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

        private void SetupTestExecute(object obj)
        {
            Packager.Setup(
                availableTrucks.Select(s => s.Clone()).ToList(),
                selectedPackages.Select(s => s.Clone()).ToList()
                );
        }

        private async void RunExecute(object obj)
        {
            results = new ObservableCollection<Truck>();
            (await Packager.Pack()).ForEach(results.Add);
        }
    }
}
