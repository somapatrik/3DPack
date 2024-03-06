//---------------------------------------------------------------------------

#ifndef utilsH
#define utilsH
//---------------------------------------------------------------------------
struct Cut{
	 long TopX; // top-left corner polong
	 long TopY;
	 long BottomX; //bottom-right corner polong
	 long BottomY;
	 long Thickness;
};

struct Waste{
	 long TopX; // top-left corner polong
	 long TopY;
	 long BottomX; //bottom-right corner polong
	 long BottomY ;
};

struct Piece{
	 long TopX; // top-left corner polong
	 long TopY;
	 long BottomX; //bottom-right corner polong
	 long BottomY;
	 long DemandIndex;
	 long ExternalIndex;
	 long Rotated;
};


struct SheetInfo{
	 long SheetIndex;
	 long length;
	 long width;
	 double CoveredSurface;
	 long NumCuts;
	 Cut* Cuts;
	 long NumPieces;
	 Piece* Pieces;
	 long NumWastes;
	 Waste* Wastes;
	 SheetInfo();
	 ~SheetInfo();
};

#endif
