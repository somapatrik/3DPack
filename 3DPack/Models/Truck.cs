

namespace _3DPack.Models
{
    public class Truck
    {
        public int Width { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }
        public int Levels { get; set; }

        public List<Floor> Floors { get; set; }

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
    }
}
