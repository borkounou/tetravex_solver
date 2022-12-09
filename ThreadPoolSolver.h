#ifndef _THREADPOOLSOLVER_H_
#define _THREADPOOLSOLVER_H_
#include <vector>
#include <stack>
#include <thread>
#include <mutex>
using namespace std;

class ThreadPoolSolver{
public:
    mutex queue_mutex;
    
    // void addThread(thread* t);
      void addThreadToSolver(thread* localThread);
    // Joindre les les differents threads:

    void queueThreadJoin();

    // Detruire ou arreter le thread
    void stopThread();

// declarer un vector de different thread
vector<thread*> threads;      
};

#endif

