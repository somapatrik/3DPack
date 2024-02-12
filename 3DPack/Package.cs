namespace _3DPack
{
    public class Package
    {
        public Guid Id { get; set; }
        public string Name { get; private set; }
        public int Width { get; private set; }
        public int Height { get; private set; }
        public int Length { get; private set; }
        public bool Stackable { get; private set; }
        public int BaseArea { get; private set; }
        public int PackageArea { get; private set; }
        public int Volume { get; private set; }

        public int Cut_Id { get; private set; }

        public int LargerDimension => Length > Width ? Length : Width;

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

        public static Package CreateClone(Guid id, string name, int length, int width, int height, bool stackable = false, int cutId = 0)
        {
            var pack = new Package(length, width, height, stackable);
            pack.SetName(name);
            pack.CloneId(id);
            pack.SetCutId(cutId);
            return pack;
        }

        public Package(int length, int width, int height, bool stackable = false)
        {
            Id = Guid.NewGuid();
            Width = width;
            Height = height;
            Length = length;
            Stackable = stackable;

            BaseArea = width * length;
            PackageArea = 2 * (length * width + length * height + width * height);
            Volume = length * width * height;
        }

        public void SetName(string name)
        {
            Name = name;
        }

        public void CloneId(Guid id)
        {
            Id = id;
        }

        public void SetCutId(int id)
        {
            Cut_Id = id;
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

        public Package Clone()
        {
            return CreateClone(Id, Name, Length, Width, Height, Stackable, Cut_Id);
        }
    }
}
