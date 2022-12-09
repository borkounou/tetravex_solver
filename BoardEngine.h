#ifndef _BOARDENGINE_H_
#define _BOARDENGINE_H_
#include <vector>
#include "TilePiece.h"
using namespace std;
class BoardEngine{

public:
  // Constructeur 
    BoardEngine(int dim);
    // Placer le pion 
    bool placeTile(TilePiece* piece, int posx, int posy);
    // Enlever un pion de la position specifiée
    void removeTile(int posx, int posy);
    // Afficher le plateau
    void displayT();
    // Retourne la dimension du tableau 
    int getDimension();
    static void displayT(vector<TilePiece*> v);
    TilePiece* getTileAt(int posx, int posy);
    bool placableTile(TilePiece* piece, int posx, int posy);
 

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
};

#endif
