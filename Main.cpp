#include <iostream>
#include "ControllerEngine.h"
using namespace std;

// fonction declarative
void sequential(ControllerEngine* solver);
void parallel(ControllerEngine* solver);
void pool(ControllerEngine* solver);


// Execution de l'algorithme de backtracking sequentiel
void sequential(ControllerEngine* solver){

    cout<<"Sequential backtracking result is:"<<endl;
    solver->sequentialSolverBactrack();
    cout<<"End of the computation"<<endl;

}

// Execution de l'algorithme backtracking parallel
void parallel(ControllerEngine* solver){
    cout<<"Parallel backtracking result is:"<<endl;
    solver->parallelSolver(20);
    cout<<"End of the computation"<<endl;

}


//Execution de thread-pool
void pool(ControllerEngine* solver){

    cout<<"Parallel threadpool result is:"<<endl;
    solver->parallelBacktrackingSolver(20);
    cout<<"End of the computation"<<endl;

}

// final main function to run:

int main(){
    // initaliser et le jeu et inserer les données
   

    GameEngine game = GameEngineReader::readDataFile("./5x5.txt");
    ControllerEngine* solver = new ControllerEngine(&game);

    int algo = 1;
    switch(algo){
    case 1:
        sequential(solver);
        break;

    case 2:
        parallel(solver);
        break;

    case 3:
        pool(solver);
        break;

    
    default:
        cout<<"Wrong entree, please try again"<<endl;
        break;
    }



    return 0;
}



