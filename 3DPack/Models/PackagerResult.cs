
namespace _3DPack.Models
{
    public class PackagerResult
    {
        public List<Package> Packed { get; set; }
        public List<Package> Unpacked { get; set; } 
        public List<Truck> Trucks { get; set; } 


        public PackagerResult()
        {
            Packed = new List<Package>();
            Unpacked = new List<Package>();
            Trucks = new List<Truck>();
        }
    }
}
