

#ifndef PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H
#define PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H


#include "../concurrency/process/DataReceiverProcess.h"

class StatisticsCreator {
public:
    /**
     * Constructor.
     */
    StatisticsCreator();

    /**
     * Destructor.
     */
    ~StatisticsCreator();

    /**
     * Create statistics.
     * Returns empty list if was created (child process), process info otherwise.
     */
    ProcessInfoList createStatistics() const;
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H
