// ---------------------------------------------------------------------------

#pragma hdrstop

#include "utils.h"
#include <stdio.h>
// ---------------------------------------------------------------------------

#pragma package(smart_init)

SheetInfo::SheetInfo()
{
  SheetIndex = -1;
  length = 0;
  width = 0;
  CoveredSurface = 0;
  NumCuts = 0;
  Cuts = NULL;
  NumPieces = 0;
  Pieces = NULL;
  NumWastes = 0;
  Wastes = NULL;

}

// ---------------------------------------------------------------------------
SheetInfo::~SheetInfo()
{
  if (Wastes)
	delete[]Wastes;
  if (Pieces)
	delete[]Pieces;
  if (Cuts)
	delete[]Cuts;

  SheetIndex = -1;
  length = 0;
  width = 0;
  CoveredSurface = 0;
  NumCuts = 0;
  Cuts = NULL;
  NumPieces = 0;
  Pieces = NULL;
  NumWastes = 0;
  Wastes = NULL;
}
// ---------------------------------------------------------------------------
