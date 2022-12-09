#include "TilePiece.h"


TilePiece::TilePiece(int left, int top, int right, int bottom){
    // Axe vertical
    vert = DirectionAxis(bottom, top);
    // axe horizontal 
    hori = DirectionAxis(left, right);
}

void TilePiece::setPlacedTile(bool _placed){
    placed = _placed;
}

bool TilePiece::isPlacedTile(){
    return placed;
}