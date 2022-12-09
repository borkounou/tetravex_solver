#include "TilePiece.h"




void TilePiece::setPlacedTile(bool _placed){
    placed = _placed;
}

bool TilePiece::isPlacedTile(){
    return placed;
}

TilePiece::TilePiece(int left, int top, int right, int bottom){

    // axe horizontal 
    hori = DirectionAxis(left, right);
    // Axe vertical
    vert = DirectionAxis(bottom, top);
}