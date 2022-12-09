#include "BoardEngine.h"
#include <string>
#include <iostream>

BoardEngine::BoardEngine(int _size){
    dimension = _size;
    for(int i = 0; i < dimension; i++){
        vector<TilePiece*> line;
        for(int j = 0; j < dimension; j++){
            line.push_back(NULL);
        }
        plateau.push_back(line);
    }
}

int BoardEngine::getDimension(){
    return dimension;
}

TilePiece* BoardEngine::getTileAt(int posx, int posy){
    return plateau[posx][posy];
}

bool BoardEngine::placableTile(TilePiece* piece, int posx, int posy){
    if(posx < 0 || posy < 0 || posx > dimension-1 || posy > dimension-1) return false;
    if(plateau[posx][posy] != NULL) return false;
    for(int i : {-1, 1}){
        if(posx + i >= 0 && posx + i <= dimension-1){
            if(plateau[posx+i][posy] != NULL){
                if(plateau[posx+i][posy]->vert.get(i) != piece->vert.get(-i)) return false;
            }
        }
        if(posy + i >= 0 && posy + i <= dimension-1){
            if(plateau[posx][posy+i] != NULL){
                if(plateau[posx][posy+i]->hori.get(-i) != piece->hori.get(i)) return false;
            }
        }
    }

    return true;
}

bool BoardEngine::placeTile(TilePiece* piece, int posx, int posy){
    if(placableTile(piece, posx, posy)){
        plateau[posx][posy] = piece;
        piece->setPlacedTile(true);
        return true;
    }

    return false;
}

void BoardEngine::removeTile(int posx, int posy){
    plateau[posx][posy] = NULL;
}

void BoardEngine::displayT(){
    for(vector<TilePiece*> v : plateau){
        BoardEngine::displayT(v);
    }
}

void BoardEngine::displayT(vector<TilePiece*> v){
    string rows[4] = {"","","",""};
    for(TilePiece * p : v){
        string tileValues[4] = {"#", "#", "#", "#"};
        if(p != NULL){
            tileValues[0] = to_string(p->hori.get(-1));
            tileValues[1] = to_string(p->vert.get(1));
            tileValues[2] = to_string(p->hori.get(1));
            tileValues[3] = to_string(p->vert.get(-1));
        }
        rows[0] += "|###";
        rows[1] += "| "+tileValues[1]+" ";
        rows[2] += "|"+tileValues[0]+" "+tileValues[2];
        rows[3] += "| "+tileValues[3]+" ";
    }
    for(string row : rows){
        cout << row+"|" <<endl;
    
    }
}