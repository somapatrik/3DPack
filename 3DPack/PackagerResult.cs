
namespace _3DPack
{
    public class PackagerResult
    {
        public List<Truck> Trucks { get; set; }

        public int NumberOfTrucks
        {
            get { return Trucks.Where(x => x.Name == "Truck").Count(); }
            set { }
        }

        public int NumberOfVans => Trucks.Where(x => x.Name == "Van").Count();
    }
}
