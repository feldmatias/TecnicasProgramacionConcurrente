#ifndef PRIMAVERA_CONCURRENTE_PROCESS_H
#define PRIMAVERA_CONCURRENTE_PROCESS_H


#include "../comunication/comunicators/ExitComunicator.h"
#include "Runnable.h"

class Process {
private:
    ExitComunicator exitComunicator;
    Runnable& runnable;

public:
    /**
     * Create a process with a runnable.
     */
    explicit Process(Runnable& runnable);

    /**
     * Destructor.
     */
    ~Process();

    /**
     * Start the process.
     */
    void run();
};


#endif //PRIMAVERA_CONCURRENTE_PROCESS_H
