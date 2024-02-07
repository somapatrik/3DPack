
using System.Drawing;

namespace _3DPack.Models
{
    public class PlacementResult
    {
        public Package Package { get; set; }
        public Floor Floor { get; set; }
        public Point PlacementPoint { get; set; }
        public int RemainingLDM { get; set; }
    }
}
