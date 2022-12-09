#include "GameEngine.h"
#include <stddef.h>
#include <iostream>

GameEngine::GameEngine(int _size){
    size = _size;
    board = new BoardEngine(size);
}

void GameEngine::addTileToBoard(TilePiece *p){
    if(stockage.size() < size^2){
         stockage.push_back(p);
    }
}

void GameEngine::removeTileFromBoard(int x, int y){
    TilePiece *piece = board->getTileAt(x, y);
    if(piece != NULL){
        board->removeTile(x, y);
        piece->setPlacedTile(false);
    }
}

void GameEngine::displayBoardResult(){
    board->displayT();
}

void GameEngine::displayStockage(){
    BoardEngine::displayT(stockage);
}

bool GameEngine::moveTile(TilePiece *p, int x, int y){
    return board->placeTile(p, x, y);
}

bool GameEngine::stockageIsEmpty(){
    for(TilePiece *p : stockage){
        if(!p->isPlacedTile()) return false;
    }
    return true;
}

GameEngine GameEngine::copyBoard(){
    GameEngine gamecp(size);
    for(TilePiece* p : stockage){
        gamecp.addTileToBoard(new TilePiece(p->hori.get(-1), p->vert.get(1), p->hori.get(1), p->vert.get(-1)));
    }
    return gamecp;
}