namespace _3DPack
{
    public class Packager
    {
        List<Truck> Trucks { get; set; }
        List<Package> Packages { get; set; }

        public Packager()
        {
            Trucks = new List<Truck>();
            Packages = new List<Package>();
        }

        public void Setup(List<Truck> trucks, List<Package> packages)
        {
            Trucks = trucks;
            Packages = packages;
        }

        public void Pack()
        {
            Run();
        }

        private List<Truck> Run()
        {
            var ResultsTrucks = new List<Truck>();

            List<Package> NotPacked = Packages.Select(p => p.Clone()).ToList();
            bool allPacked = false;

            while (!allPacked)
            {
                Truck winnerTruck = TryAllTrucks(NotPacked);
                ResultsTrucks.Add(winnerTruck);

                winnerTruck.Packages.ForEach(stored =>
                {
                    NotPacked.RemoveAll(r => r.Id == stored.Id);
                });

                allPacked = !NotPacked.Any();
            }

            return ResultsTrucks;
        }

        private Truck TryAllTrucks(List<Package> packages)
        {
            List<Truck> availableTrucks = Trucks.Select(t => t.Clone()).ToList();
            List<Truck> checkedTrucks = new List<Truck>();

            foreach (var truck in availableTrucks)
            {
                truck.StorePackages(packages.Select(p => p.Clone()).ToList());
                checkedTrucks.Add(truck);
            }

            return checkedTrucks.OrderByDescending(t => t.UsedArea).ThenByDescending(p => p.Packages.Count).First();
        }

    }
}
