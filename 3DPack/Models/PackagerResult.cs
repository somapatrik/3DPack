
namespace _3DPack.Models
{
    public class PackagerResult
    {

        public List<Package> Packed => Trucks.SelectMany(p => p.Packages).ToList(); 
        public List<Truck> Trucks { get; set; } 


        public PackagerResult()
        {
            Trucks = new List<Truck>();
        }
    }
}
