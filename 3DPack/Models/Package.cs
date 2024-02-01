
using System.Drawing;

namespace _3DPack.Models
{
    public class Package
    {
        public string Name { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }
        public int Length { get; private set; }
        public bool Rotated { get; private set; }
        public bool Stackable { get; private set; }
        public int Area { get; private set; }

        public RotationType Rotation
        {
            get
            {
                if (Length == Width)
                    return RotationType.Equilateral;

                if (Length < Width)
                    return RotationType.Vertical;
                
                return RotationType.Horizontal;
            }
        }

        public static Package Create(string name, int length, int width, int height, bool stackable = false)
        {
            var pack = new Package(length, width, height, stackable);
            pack.SetName(name);
            return pack;
        }

        public Package(int length, int width, int height, bool stackable = false)
        {
            Width = width;
            Height = height;
            Length = length;
            Stackable = stackable;
            Area = width * length;
        }

        public void SetName(string name)
        {
            Name = name;
        }

        public void Rotate()
        {
            int temp = Length;
            Length = Width;
            Width = temp;
        }

        public void RotateToBeHorizontal()
        {
            if (Rotation == RotationType.Vertical)
                Rotate();
        }

        public void RotateToBeVertical()
        {
            if (Rotation == RotationType.Horizontal)
                Rotate();
        }


    }
}
