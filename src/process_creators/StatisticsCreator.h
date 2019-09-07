

#ifndef PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H
#define PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H


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
     * Returns true if was created (child process), false otherwise.
     */
    bool createStatistics() const;
};


#endif //PRIMAVERA_CONCURRENTE_STATISTICSCREATOR_H
