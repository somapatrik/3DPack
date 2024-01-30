
using System.Drawing;

namespace _3DPack.Models
{
    public class Package
    {
        public int Width { get; set; }
        public int Height { get; set; }
        public int Length { get; set; }
        public bool Stackable { get; set; }

        public Package(int length, int width, int height, bool stackable = false)
        {
            Width = width;
            Height = height;
            Length = length;
            Stackable = stackable;
        }   


    }
}
