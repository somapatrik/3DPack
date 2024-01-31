
using System.Drawing;

namespace _3DPack.Models
{
    public class Package
    {
        public string Name { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }
        public int Length { get; private set; }
        public bool Stackable { get; private set; }

        public static Package Create(string name, int length, int width, int height, bool stackable = false)
        {
            var pack = new Package(length,width,height,stackable) 
            pack.SetName(name);
            return pack;
        }

        public Package(int length, int width, int height, bool stackable = false)
        {
            Width = width;
            Height = height;
            Length = length;
            Stackable = stackable;
            Name = name;
        }

        public void SetName(string name)
        {
            Name = name;
        }


    }
}
