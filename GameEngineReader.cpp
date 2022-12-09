
#include "GameEngineReader.h"
#include <fstream>
#include <iostream>

GameEngine GameEngineReader::readDataFile(string file_path){
    // La dimension du fichier, par exemple 7 pour 7x7
    int size {0};
    // la lecture de fichier text
    std::ifstream infile(file_path);

    infile >> size >> size;
        // Les differents axes d'un pion donné
    int left;
    int top;
    int right;
    int bottom;
    // declaration de gameEngine
    GameEngine game(size);

    while(infile >> left >> top >> right >> bottom){
        // ajouter de pion au tableau : par exemple un pion peut contenir 4 chiffres : 1234
        game.addTileToBoard(new TilePiece(left, top, right, bottom));
        
    }

    return game;
}