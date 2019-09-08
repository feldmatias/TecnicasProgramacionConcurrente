

#ifndef PRIMAVERA_CONCURRENTE_PARENTCOMUNICATOR_H
#define PRIMAVERA_CONCURRENTE_PARENTCOMUNICATOR_H


#include "ExitComunicator.h"
#include "StatisticsComunicator.h"

class ParentComunicator {
private:
    ExitComunicator exitComunicator;
    StatisticsComunicator statisticsComunicator;

public:
    /**
     * Constructor.
     */
    ParentComunicator();

    /**
     * Destructor.
     */
    ~ParentComunicator();

    /**
     * Start receiving user input.
     */
    void start();
};


#endif //PRIMAVERA_CONCURRENTE_PARENTCOMUNICATOR_H
