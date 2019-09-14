

#ifndef PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H
#define PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H


#include "../concurrency/Process.h"

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
     * Returns empty list if was created (child process), process name otherwise.
     */
    ProcessNames createStatistics() const;
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H
