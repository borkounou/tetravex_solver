
#include "ThreadPoolSolver.h"
using namespace std;

//constructeur vide
ThreadPoolSolver::ThreadPoolSolver(){}
// ajouter des threads a la liste the threads 
void ThreadPoolSolver::addThreadToSolver(thread* t){threads.push_back(t);}
// Joindre les differents threads 
void ThreadPoolSolver::queueThreadJoin(){for(thread* t : threads){t->join();}}
// Arreter le threads
void ThreadPoolSolver::stopThread(){

    // Faire une boucle pour detruire le thread
    for(thread* t : threads){
        t->~thread();
   }
}