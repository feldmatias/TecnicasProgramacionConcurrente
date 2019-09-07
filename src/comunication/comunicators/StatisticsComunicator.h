

#ifndef PRIMAVERA_CONCURRENTE_STATISTICSCOMUNICATOR_H
#define PRIMAVERA_CONCURRENTE_STATISTICSCOMUNICATOR_H

#define STATISTICS_CHAR 's'

#include "../../concurrency/SharedMemory.h"

class StatisticsComunicator {
private:
    SharedMemory<int> sharedMemory;
    int lastReceived;

public:
    StatisticsComunicator();

    ~StatisticsComunicator();

    void showStatistics();

    bool shouldShowStatistics();
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICSCOMUNICATOR_H
