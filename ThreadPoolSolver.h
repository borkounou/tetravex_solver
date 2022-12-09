#include <vector>
#include <stack>
#include <thread>
#include <mutex>
using namespace std;

class ThreadPoolSolver{

    // declarer un vector de different thread
    vector<thread*> threads;      

public:
    mutex queue_mutex;
    ThreadPoolSolver();
    // void addThread(thread* t);
      void addThreadToSolver(thread* localThread);
    // Joindre les les differents threads:

    void queueThreadJoin();

    // Detruire ou arreter le thread
    void stopThread();
};

