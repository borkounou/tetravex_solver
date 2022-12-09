#include "ControllerEngine.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

void ControllerEngine::sequentialSolverBactrack(){
    // Le temps de commencement
    start = chrono::high_resolution_clock::now(); 
    // Une brute force simple qui commence par la position de plateau 0,0
    simpleBruteforceSolver(0, 0);
}


void ControllerEngine::parallelBruteforceSolver(int posx, int posy, GameEngine &gamecp){
    if(gamecp.stockageIsEmpty()){
        auto stop = chrono::high_resolution_clock::now();
        cout << "Computation time is: " << chrono::duration_cast<chrono::duration<double>>(stop - start).count() << "s"<<endl;;
        gamecp.displayBoardResult();
        tpool.stopThread();
        return;
    }
    for(TilePiece *p : gamecp.getStockage()){
        if(!p->isPlacedTile()){
            if(gamecp.moveTile(p, posx, posy)){
                int nextx = posx;
                int nexty = posy+1;
                if(posy == gamecp.getSizeOfBoard()-1){
                    nextx ++;
                    nexty = 0;
                }
                parallelBruteforceSolver(nextx, nexty, gamecp);
                gamecp.removeTileFromBoard(posx, posy);
            }
        }
    }
}

// La resolution en parallele
void ControllerEngine::parallelSolver(int threadId){
    GameEngine gac = game->copyBoard();
    for(currentPiece=0; currentPiece<game->getStockage().size(); currentPiece++){
        gac.removeTileFromBoard(0,0);
        gac.moveTile(gac.getStockage()[currentPiece], 0, 0);
        tpool.queue_mutex.lock();
        tpool.queue_mutex.unlock();
        parallelBruteforceSolver(0, 1 , gac);

    }
}

// Thread-pool resolution
void ControllerEngine::parallelBacktrackingSolver(int amount){
    int i =0;
    while(i<amount){
        tpool.addThreadToSolver(new thread(&ControllerEngine::parallelSolver, this, i));
        i++;
    }

    start = chrono::high_resolution_clock::now(); 
    tpool.queueThreadJoin();

}


//Simple recursive brute force solver
void ControllerEngine::simpleBruteforceSolver(int posx, int posy){
    if(game->stockageIsEmpty()){
        auto stop = chrono::high_resolution_clock::now();
        cout << "Computation time is: " << chrono::duration_cast<chrono::duration<double>>(stop - start).count() << "seconde"<<endl;
        game->displayBoardResult();
        exit(0);
        return;
    }
    for(TilePiece* p : game->getStockage()){
        if(!p->isPlacedTile()){
            if(game->moveTile(p, posx, posy)){
                int nx = posx;
                int ny = posy+1;
                if(posy == game->getSizeOfBoard()-1){
                    nx ++;
                    ny = 0;
                }
                simpleBruteforceSolver(nx, ny);
                game->removeTileFromBoard(posx, posy);
            }
        }
    }
}

// Constructeur de Controller engine qui a pour parametre le gameEngine
ControllerEngine::ControllerEngine(GameEngine* gc){
    game = gc;
    currentPiece = 0;
}
