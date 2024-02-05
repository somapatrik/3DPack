

namespace _3DPack.Models
{
    public class Packager
    {
        List<Truck> Trucks { get; set; }
        List<Package> Packages { get; set; }
        List<List<Package>> PackagePermutations { get; set; }
        List<PackagerResult> Results { get; set; }

        public int PermutationCount => PackagePermutations.Count();
        public Packager()
        {
            Trucks = new List<Truck>();
            Packages = new List<Package>();
        }

        public void Ready(List<Truck> trucks, List<Package> packages)
        {
            Trucks = trucks;
            Packages = packages;
            PermutatePackages();
        }

        public async Task<List<PackagerResult>> Optimize()
        {
           await Run();
            return Results;
        }

        private Task Run()
        {
            Results = new List<PackagerResult>();

            foreach (List<Package> permutation in PackagePermutations)
            {
                PackagerResult result = new PackagerResult();
               // List<Package> toPack = permutation.Select(s => s.Clone()).ToList();

                List<Package> Packed = new List<Package>();
                List<Package> NotPacked = permutation.Select(s => s.Clone()).ToList(); 

                bool allPacked = false;

                while (!allPacked) 
                { 
                    Truck winnerTruck = CheckAllTrucks(NotPacked);
                    result.Trucks.Add(winnerTruck);

                    winnerTruck.Packages.ForEach(packed => NotPacked.Remove(packed));

                    allPacked = result.Trucks.Sum(allPacked => allPacked.Packages.Count()) == permutation.Count();
                }

                Results.Add(result);
            }

            return Task.CompletedTask;
        }

        private Truck CheckAllTrucks(List<Package> packages)
        {
            List<Truck> availableTrucks = new List<Truck>();
            List<Truck> checkedTrucks = new List<Truck>();

            availableTrucks = Trucks.Select(t => t.Clone()).ToList();

            foreach (var truck in availableTrucks)
            {
                foreach (var package in packages)
                {
                    truck.InsertPackage(package);
                }
                checkedTrucks.Add(truck);
            }

            // Most used area with the most packages inside
            return checkedTrucks.OrderByDescending(t => t.UsedArea).ThenByDescending(p=>p.Packages.Count).First();
        }

        private void PermutatePackages()
        {
            PackagePermutations = GetPermutations(Packages);
        }

        private List<List<T>> GetPermutations<T>(List<T> list)
        {
            List<List<T>> result = new List<List<T>>();
            GeneratePermutations(list, 0, list.Count - 1, result);
            return result;
        }

        #region Permutations
        private void GeneratePermutations<T>(List<T> list, int left, int right, List<List<T>> result)
        {
            if (left == right)
            {
                result.Add(new List<T>(list));
            }
            else
            {
                for (int i = left; i <= right; i++)
                {
                    Swap(list, left, i);
                    GeneratePermutations(list, left + 1, right, result);
                    Swap(list, left, i); 
                }
            }
        }

        private void Swap<T>(List<T> list, int i, int j)
        {
            T temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
        
        #endregion
    }
}
