
namespace _3DPack
{
    public class PackagerResult
    {
        public List<Truck> Trucks { get; set; }

        public int NumberOfTrucks => Trucks.Where(x => x.Name == "Truck").Count();

        public int NumberOfVans => Trucks.Where(x => x.Name == "Van").Count();
    }
}
