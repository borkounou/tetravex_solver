#include "ControllerEngine.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

// ControllerEngine::ControllerEngine(){

// }

ControllerEngine::ControllerEngine(GameEngine* _game){
    game = _game;
    currentPiece = 0;
}


void ControllerEngine::sequentialSolverBactrack(){

    start = chrono::high_resolution_clock::now(); 
    simpleBruteforceSolver(0, 0);
}
//Simple recursive brute force solver
void ControllerEngine::simpleBruteforceSolver(int x, int y){
    if(game->stockageIsEmpty()){
        auto stop = chrono::high_resolution_clock::now();
        cout << "Computation time is: " << chrono::duration_cast<chrono::duration<double>>(stop - start).count() << "s"<<endl;
        game->displayBoardResult();
        exit(0);
        return;
    }
    for(TilePiece* p : game->getStockage()){
        if(!p->isPlacedTile()){
            if(game->moveTile(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(y == game->getSizeOfBoard()-1){
                    nextx ++;
                    nexty = 0;
                }
                simpleBruteforceSolver(nextx, nexty);
                game->removeTileFromBoard(x, y);
            }
        }
    }
}

void ControllerEngine::parallelBruteforceSolver(int x, int y, GameEngine &gamecp){
    if(gamecp.stockageIsEmpty()){
        auto stop = chrono::high_resolution_clock::now();
        cout << "Computation time is: " << chrono::duration_cast<chrono::duration<double>>(stop - start).count() << "s"<<endl;;
        gamecp.displayBoardResult();
        tpool.stopThread();
        return;
    }
    for(TilePiece *p : gamecp.getStockage()){
        if(!p->isPlacedTile()){
            if(gamecp.moveTile(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(y == gamecp.getSizeOfBoard()-1){
                    nextx ++;
                    nexty = 0;
                }
                parallelBruteforceSolver(nextx, nexty, gamecp);
                gamecp.removeTileFromBoard(x, y);
            }
        }
    }
}

void ControllerEngine::parallelSolver(int threadId){
    GameEngine gamecp = game->copyBoard();
    while(currentPiece < game->getStockage().size()){
        gamecp.removeTileFromBoard(0,0);
        gamecp.moveTile(gamecp.getStockage()[currentPiece], 0, 0);
        tpool.queue_mutex.lock();
        currentPiece++;
        tpool.queue_mutex.unlock();
        parallelBruteforceSolver(0, 1 , gamecp);
    }
}

void ControllerEngine::parallelBacktrackingSolver(int amount){
    for(int i = 0; i < amount; i++){
        tpool.addThreadToSolver(new thread(&ControllerEngine::parallelSolver, this, i));
    }
    start = chrono::high_resolution_clock::now(); 
    tpool.queueThreadJoin();
    
}