

#ifndef PRIMAVERA_CONCURRENTE_LOGGERCREATOR_H
#define PRIMAVERA_CONCURRENTE_LOGGERCREATOR_H


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
     * Returns true if was created (child process), false otherwise.
     */
    bool createLogger() const;
};


#endif //PRIMAVERA_CONCURRENTE_LOGGERCREATOR_H
