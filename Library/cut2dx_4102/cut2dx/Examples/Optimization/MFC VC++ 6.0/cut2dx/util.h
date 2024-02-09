


struct cut{
	long tx, ty, bx, by, thick;
};

struct part{
	long tx, ty, bx, by, rotated;
};

struct waste{
	long tx, ty, bx, by;
};

extern cut *cuts;
extern part *parts;
extern waste *wastes; 

extern long num_cuts;
extern long num_parts;
extern long num_wastes;

extern long Length;
extern long Width;