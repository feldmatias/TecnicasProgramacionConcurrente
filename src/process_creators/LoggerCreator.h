

#ifndef PRIMAVERA_CONCURRENTE_LOGGERCREATOR_H
#define PRIMAVERA_CONCURRENTE_LOGGERCREATOR_H


#include "../concurrency/Process.h"

class LoggerCreator {
public:
    /**
     * Constructor.
     */
    LoggerCreator();

    /**
     * Destructor.
     */
    ~LoggerCreator();

    /**
     * Create logger.
     * Returns empty if was created (child process), Process info otherwise.
     */
    ProcessInfoList createLogger() const;
};


#endif //PRIMAVERA_CONCURRENTE_LOGGERCREATOR_H
