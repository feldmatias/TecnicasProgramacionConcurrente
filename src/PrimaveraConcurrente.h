

#ifndef PRIMAVERA_CONCURRENTE_PRIMAVERACONCURRENTE_H
#define PRIMAVERA_CONCURRENTE_PRIMAVERACONCURRENTE_H


#include "concurrency/process/ProcessInfo.h"

class PrimaveraConcurrente {
private:
    ProcessInfoList processes;

    /**
     * Receive user input.
     */
     void receiveUserInput();

public:
    /**
     * Constructor.
     */
    PrimaveraConcurrente();

    /**
     * Destructor, finishes all child process.
     */
    ~PrimaveraConcurrente();

    /**
     * Start the program.
     */
    void start();
};


#endif //PRIMAVERA_CONCURRENTE_PRIMAVERACONCURRENTE_H
