#include "GameEngine.h"
#include <stddef.h>
#include <iostream>
#define MAX 1
#define MIN -1


// Ajouter des pions dans le plateau 
void GameEngine::addTileToBoard(TilePiece *p){
    if(stockage.size() < size^2){
         stockage.push_back(p);
    }
}

// enlever les pions du tableau
void GameEngine::removeTileFromBoard(int x, int y){
    TilePiece *piece = board->getTileAt(x, y);
    if(piece != NULL){
        board->removeTile(x, y);
        piece->setPlacedTile(false);
    }
}

// Afficher le resultat du plateau ou tableau
void GameEngine::displayBoardResult(){
    board->displayT();
}
// Montrer la liste de pions
void GameEngine::displayStockage(){
    BoardEngine::displayT(stockage);
}
// deplacer les pions
bool GameEngine::moveTile(TilePiece *tile, int posx, int posy){
    return board->placeTile(tile, posx, posy);
}
// copy de gameEngine pour d'autres operations
GameEngine GameEngine::copyBoard(){
    GameEngine gamecopy(size);
    for(TilePiece* p : stockage){
        auto hor_moins =p->hori.get(MIN); 
        auto hors_plus =  p->hori.get(MAX);
        auto vert_plus =  p->vert.get(MAX);
        auto vert_moins = p->vert.get(MIN);
        gamecopy.addTileToBoard(new TilePiece(hor_moins,vert_plus, hors_plus, vert_moins));
    }
    // retourne le gameEngine
    return gamecopy;
}


GameEngine::GameEngine(int dim){
    size = dim;
    board = new BoardEngine(size);
}


// Verifier si le stockage est vide ou non
bool GameEngine::stockageIsEmpty(){
    for(TilePiece *p : stockage){
        if(!p->isPlacedTile()) {
            return false;
        }
    }
    return true;
}


