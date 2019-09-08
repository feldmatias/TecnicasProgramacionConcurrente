

#ifndef PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H
#define PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H

#define EXIT_CHAR 'q'

#include "../../concurrency/SharedMemory.h"

class ExitComunicator {
private:
    SharedMemory<bool> sharedMemory;

public:
    /**
     * Constructor.
     */
    ExitComunicator();

    /**
     * Destructor.
     */
    ~ExitComunicator();

    /**
     * Comunicate to childs that they need to exit.
     */
    void setExit();

    /**
     * If child should exit or not.
     */
    bool shouldExit() const;
};


#endif //PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H
