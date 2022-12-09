#include <vector>
#include "TilePiece.h"
using namespace std;
class BoardEngine{
private:
 //Definir les variables suivantes: dim la dimension
    int dimension;
      // un vector des vector qui est la representation du tableau du jeu:
    /*
        Un exemple d'un tableau vide de dimension 3X3 du jeu:
        gridBoard= {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        }
        Chaque 0 est consideré un pion de 4 axes: exemple d'un pion: 4 
                                                                   1   3
                                                                     2 
                                                                     */
    vector<vector<TilePiece*> > plateau;

public:
    BoardEngine();
    BoardEngine(int _size);
    // Retourne la dimension du tableau 
    int getDimension();
    TilePiece* getTileAt(int posx, int posy);
    bool placableTile(TilePiece* piece, int posx, int posy);
    bool placeTile(TilePiece* piece, int posx, int posy);
    void removeTile(int posx, int posy);
    void displayT();
    static void displayT(vector<TilePiece*> v);
};
