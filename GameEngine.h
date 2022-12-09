
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
private:
    int size;
    BoardEngine* board;
    vector<TilePiece*> stockage;

public:
   GameEngine();
    GameEngine(int _size);
    vector<TilePiece*> getStockage(){ return stockage; }
    int getSizeOfBoard(){return size;}
    void addTileToBoard(TilePiece* p);
    void removeTileFromBoard(int x, int y);
    void displayBoardResult();
    bool moveTile(TilePiece *p, int x, int y);
    void displayStockage();
    bool stockageIsEmpty();
    GameEngine copyBoard();

  
};



