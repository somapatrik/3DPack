namespace _3DPack.Models
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

        public void Optimize(List<Truck> trucks, List<Package> packages)
        {
            Trucks.ForEach(Truck truck in Trucks)
            {

            }
        }

    }
}
