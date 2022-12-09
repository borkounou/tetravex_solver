
#ifndef _GAMEENGINE_H_
#define  _GAMEENGINE_H_
#include "BoardEngine.h"
using namespace std;

// Le moteur du jeu de tetravex
/*
Dans ce cas, il nous faut la logique:
- d'ajouter des pions
- Enlever des pions
- deplacer les pions
- afficher les pions*/

class GameEngine{

public:
    // Afficher le resultat du tableau 
    void displayBoardResult();
    // deplacer le pion 
    bool moveTile(TilePiece *tilePiece, int x, int y);
    // Afficher les pieces 
    void displayStockage();
    // verifier s'il reste encore de pions
    bool stockageIsEmpty();
    // une copie de gameEngine
    GameEngine copyBoard();
    GameEngine(int dim);
    // les differentes valeurs de stockage
    vector<TilePiece*> getStockage(){ return stockage; }
    // La dimension du tableau 
    int getSizeOfBoard(){return size;}
    //ajouter de pion au tableau 
    void addTileToBoard(TilePiece* p);
    // Supprimer de pion de tableaus
    void removeTileFromBoard(int x, int y);

private:
// La dimension du tableau
    int size;
    // le tableau 
    BoardEngine* board;
    // le stockage de pions
    vector<TilePiece*> stockage;

  
};

#endif



