

#ifndef PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H
#define PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H

#define EXIT_CHAR 'q'

#include "../../concurrency/SharedMemory.h"

class ExitComunicator {
private:
    SharedMemory<bool> sharedMemory;

public:
    ExitComunicator();

    ~ExitComunicator();

    void setExit();

    bool isExit() const;
};


#endif //PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H
