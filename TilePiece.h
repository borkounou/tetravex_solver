#ifndef _TILEPIECE_H_
#define _TILEPIECE_H_
#include "DirectionAxis.h"

// Tetravex piece containing 4 values 
using namespace std;
class TilePiece{
public:
    /*The axis of the tile are: left, top right and bottom each contains a value which vary from 0 to Dimension*/

    TilePiece(int left, int top, int right, int bottom);
    bool placed;
    void setPlacedTile(bool _placed);
    bool isPlacedTile();
    DirectionAxis vert;
    DirectionAxis hori;
    
};

#endif


