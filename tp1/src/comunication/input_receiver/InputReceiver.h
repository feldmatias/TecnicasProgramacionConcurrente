#ifndef PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H
#define PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H


#include "../../concurrency/process/ProcessInfo.h"

#define STATISTICS_CHAR 's'
#define EXIT_CHAR 'q'

class InputReceiver {
private:
    ProcessInfoList processes;

    /**
     * Finish all processes.
     */
    void exit();

    /**
     * Show statistics.
     */
    void showStatistics();


public:
    /**
     * Constructor.
     */
    explicit InputReceiver(ProcessInfoList processes);

    /**
     * Destructor.
     */
    ~InputReceiver();

    /**
     * Start receiving user input.
     */
    void start();
};


#endif //PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H
