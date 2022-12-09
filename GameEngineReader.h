#ifndef _GAMEENGINEREADER_H_
#define _GAMEENGINEREADER_H_
// Importer la classe gameEngine afin de lire le fichier des données:
#include "GameEngine.h"
#include <string>
//Import la librairie standarde string
using namespace std;
class GameEngineReader{
public:
    static GameEngine readDataFile(string file_path);
};

#endif

