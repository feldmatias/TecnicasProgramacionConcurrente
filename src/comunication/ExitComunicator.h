

#ifndef PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H
#define PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H


#include "../concurrency/SharedMemory.h"

class ExitComunicator {
private:
    SharedMemory<bool> sharedMemory;

public:
    ExitComunicator();

    ~ExitComunicator();

    void start();

    bool isExit() const;
};


#endif //PRIMAVERA_CONCURRENTE_EXITCOMUNICATOR_H
