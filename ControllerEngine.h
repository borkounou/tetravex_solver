#ifndef _CONTROLLERENGINE_H_
#define _CONTROLLERENGINE_H_
#include "GameEngineReader.h"
#include "ThreadPoolSolver.h"
#include <chrono>
using namespace std;
class ControllerEngine{

public:
  
    // La methode sequentielle
    void sequentialSolverBactrack();
    // simple brute force recursive
    void simpleBruteforceSolver(int posx, int posy);
    // parallele
    void parallelBruteforceSolver(int posx, int posy, GameEngine &gameEngine);
    ControllerEngine(GameEngine* gameEngine);
    // Deuxieme fonction pour faire la parallelisation
    void parallelSolver(int threadS);
    void parallelBacktrackingSolver(int amount);
 

private:
   
   // Game engine definit
    GameEngine* game;
    // la classe threadPoolsolver definie
    ThreadPoolSolver tpool;
    // le pion actuel
    int currentPiece;
    // le temps de commencement
    chrono::high_resolution_clock::time_point start;
    
};

#endif

