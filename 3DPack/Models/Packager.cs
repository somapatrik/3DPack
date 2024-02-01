

namespace _3DPack.Models
{
    public class Packager
    {
        List<Truck> Trucks { get; set; }
        List<Package> Packages { get; set; }
        List<List<Package>> PackagePermutations { get; set; }
        List<PackagerResult> Results { get; set; }

        private bool RunningTest;
        public Packager()
        {
            Trucks = new List<Truck>();
            Packages = new List<Package>();
        }

        public void Optimize(List<Truck> trucks, List<Package> packages)
        {
            Trucks = trucks;
            Packages = packages;
            PermutatePackages();

            Run();
        }

        private Task Run()
        {
            Results = new List<PackagerResult>();

            foreach (List<Package> permutation in PackagePermutations)
            {
                PackagerResult result = new PackagerResult();

                List<Package> toPack = new List<Package>();
                permutation.ForEach(per => toPack.Add(per.c));
                
                while (toPack.Count > 0) 
                { 
                    Truck winnerTruck =  CheckAllTrucks(toPack);
                    winnerTruck.Packages.ForEach(p=>toPack.Remove(p));
                    result.Trucks.Add(winnerTruck);
                }
            }

            return Task.CompletedTask;
        }

        private Truck CheckAllTrucks(List<Package> packages)
        {
            List<Truck> availableTrucks = new List<Truck>();
            List<Truck> checkedTrucks = new List<Truck>();

            Trucks.ForEach(availableTrucks.Add);

            foreach (var truck in availableTrucks)
            {
                foreach (var package in packages)
                {
                    truck.InsertPackage(package);
                }
                checkedTrucks.Add(truck);
            }

            return checkedTrucks.OrderByDescending(t => t.UsedArea).First();
        }

        private void FillTruck(Truck truck, List<Package> packages)
        {
            foreach (Package package in packages)
            {
                truck.InsertPackage(package);
            }
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
        private void GeneratePermutationsWithRotation(List<Package> list, int index, List<List<Package>> result)
        {
            if (index == list.Count)
            {
                // Přidání permutace do výsledku
                result.Add(new List<Package>(list));
            }
            else
            {
                // Není otáčený
                GeneratePermutationsWithRotation(list, index + 1, result);

                // Otáčený
                list[index].Rotate();
                GeneratePermutationsWithRotation(list, index + 1, result);
                list[index].Rotate();
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
