#include "GameEngineReader.h"
#include "ThreadPoolSolver.h"
#include <chrono>
using namespace std;
class ControllerEngine{

public:
    chrono::high_resolution_clock::time_point start;
    ControllerEngine();
    ControllerEngine(GameEngine* _game);
    void sequentialSolverBactrack();
    void simpleBruteforceSolver(int posx, int posy);
    void parallelBruteforceSolver(int posx, int posy, GameEngine &game);
    void parallelSolver(int i);
    void parallelBacktrackingSolver(int threadAmount);

private:
    GameEngine* game;
    int currentPiece;
    ThreadPoolSolver tpool;
};

