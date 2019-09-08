#include "StatisticsComunicator.h"

#define SHARED_MEMORY_KEY "StatisticsComunicatorSHM"

StatisticsComunicator::StatisticsComunicator() :
    sharedMemory(SHARED_MEMORY_KEY, 0){
    lastReceived = 0;
}

StatisticsComunicator::~StatisticsComunicator() = default;

void StatisticsComunicator::showStatistics() {
    lastReceived++;
    sharedMemory.write(lastReceived);
}

bool StatisticsComunicator::shouldShowStatistics() {
    int last = sharedMemory.read();
    if (last > lastReceived) {
        lastReceived = last;
        return true;
    }
    
    return false;
}
