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

        public async Task<List<Truck>> Pack()
        {
           return await Run();
        }

        private Task<List<Truck>> Run()
        {
            var ResultsTrucks = new List<Truck>();

            List<Package> notPacked = Packages.Select(p => p.Clone()).ToList();
            bool allPacked = false;

            while (!allPacked)
            {
                Truck winnerTruck = TryAllTrucks(notPacked);
                
                notPacked = winnerTruck.CopyUnpacked();
                ResultsTrucks.Add(winnerTruck);

                allPacked = !notPacked.Any();
            }

            return Task.FromResult(ResultsTrucks);
        }

        private Truck TryAllTrucks(List<Package> packages)
        {
            List<Truck> availableTrucks = Trucks.Select(t => t.Clone()).ToList();
            List<Truck> checkedTrucks = new List<Truck>();

            foreach (var truck in availableTrucks)
            {
                truck.AreaOptimization(packages.Select(p => p.Clone()).ToList());
                checkedTrucks.Add(truck);
            }

            return checkedTrucks.OrderByDescending(t => t.UsedArea).ThenByDescending(p => p.Packed.Count).First();
        }

    }
}
