

#ifndef PRIMAVERA_CONCURRENTE_STATISTICSCOMUNICATOR_H
#define PRIMAVERA_CONCURRENTE_STATISTICSCOMUNICATOR_H

#define STATISTICS_CHAR 's'

#include "../../concurrency/SharedMemory.h"

class StatisticsComunicator {
private:
    SharedMemory<int> sharedMemory;
    int lastReceived;

public:
    /**
     * Constructor.
     */
    StatisticsComunicator();

    /**
     * Destructor.
     */
    ~StatisticsComunicator();

    /**
     * Comunicate that statistics need to be shown.
     */
    void showStatistics();

    /**
     * If statistics need to be shown.
     */
    bool shouldShowStatistics();
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICSCOMUNICATOR_H
