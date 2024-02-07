
using System.Drawing;

namespace _3DPack
{
    public class PlacementResult
    {
        public Package Package { get; set; }
        public Floor Floor { get; set; }
        public Point PlacementPoint { get; set; }
        public int RemainingLDM { get; set; }
    }
}
