

namespace _3DPack.Models
{
    public class Truck
    {
        public string Name { get; private set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }
        public int Levels { get; set; }

        public List<Floor> Floors { get; set; }

        public static Truck Create(string name, int length, int width, int height)
        {
            var t = new Truck(length, width, height);
            t.SetName(name);
            return t;
        }

        public Truck(int length, int width, int height)
        {
            Width = width;
            Height = height;
            Length = length;

            Floors = new List<Floor>() 
            { 
                new Floor(length, width, height) 
            };
        }

        public void SetName(string name)
        {
            Name = name;
        }
    }

}
