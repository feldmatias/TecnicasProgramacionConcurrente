#ifndef PRIMAVERA_CONCURRENTE_PROCESS_H
#define PRIMAVERA_CONCURRENTE_PROCESS_H


#include "../comunication/ExitComunicator.h"
#include "Runnable.h"

class Process {
private:
    ExitComunicator exitComunicator;
    Runnable& runnable;

public:
    explicit Process(Runnable& runnable);

    ~Process();

    void run();
};


#endif //PRIMAVERA_CONCURRENTE_PROCESS_H
