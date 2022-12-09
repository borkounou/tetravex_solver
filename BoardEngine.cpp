#include "BoardEngine.h"
#include <string>
#include <iostream>

#define MAX 1
#define MIN -1
#define EMPTY NULL

void BoardEngine::displayT(vector<TilePiece*> vec){
    string rows[4] = {"","","",""};
    for(TilePiece * piece : vec){
        string tileValues[4] = {"#", "#", "#", "#"};
        if(piece != NULL){
            tileValues[0] = to_string(piece->hori.get(MIN));
            tileValues[1] = to_string(piece->vert.get(MAX));
            tileValues[2] = to_string(piece->hori.get(MAX));
            tileValues[3] = to_string(piece->vert.get(MIN));
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

/*
La logique pour d'implementation pour placer les pions dans le plateau

*/
bool BoardEngine::placableTile(TilePiece* piece, int posx, int posy){
    // Verifier si la place est acceptable pour placer la piece ou le pio
    if(posx < 0 || posy < 0 || posx > dimension-1 || posy > dimension-1) {
        return false;
        }
    // Si le plateau n'est pas vide il faut retourner 
    if(plateau[posx][posy] != EMPTY) {
        return false;
        }
    // Configure les differents parametres
    else{
        for(int i : {MIN, MAX}){
        if(posx + i >= 0 && posx + i <= dimension-1){
            if(plateau[posx+i][posy] != EMPTY){
                auto platVer = plateau[posx+i][posy]->vert.get(i);
                if( platVer!= piece->vert.get(-i)) {
                    return false;
                    }
            }
        }
        if(posy + i >= 0 && posy + i <= dimension-1){
           
            if(plateau[posx][posy+i] != EMPTY){
                auto platHori = plateau[posx][posy+i]->hori.get(-i);
                if(platHori != piece->hori.get(i)) {
                    return false;
                    }
            }
        }
    }
}

    return true;
}

// La dimension du plateau
int BoardEngine::getDimension(){
    return dimension;
}

// La piece à une position donnée: posx et posy
TilePiece* BoardEngine::getTileAt(int posx, int posy){
    // Un pion à la position posx et posy
    return plateau[posx][posy];
}

// Placer le pion à une position donnée
bool BoardEngine::placeTile(TilePiece* piece, int posx, int posy){
    // Verifier si la position est plaçable
    if(placableTile(piece, posx, posy)){
        plateau[posx][posy] = piece;
        piece->setPlacedTile(true);
        return true;
    }else{
        return false;
    }

   
}
// Enlever une pion d'une positon donnée
void BoardEngine::removeTile(int posx, int posy){
    plateau[posx][posy] = NULL;
}


// Afficher le plateau 
void BoardEngine::displayT(){
    for(vector<TilePiece*> vect : plateau){
        // Afficher le tableau de resultat
        BoardEngine::displayT(vect);
    }
}



BoardEngine::BoardEngine(int dim){
    /*
    Cette methode prend comme argument la dimension:
    @params:
       -dim: int
    et insere chaque ligne dans le plateau
    */
    dimension = dim;
    int s = 0;
    while(s<dimension){
        // la liste de pion: chaque pion est composé de 4 chiffres
        vector<TilePiece*> rowLine;
        for(int j = 0; j < dimension; j++){
            rowLine.push_back(NULL);
        }
        plateau.push_back(rowLine);
        s++;

    }
}