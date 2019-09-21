#ifndef PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H
#define PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H

#include "../../concurrency/Process.h"

#define STATISTICS_CHAR 's'
#define EXIT_CHAR 'q'

class InputReceiver {
private:
    ProcessInfoList process;

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
    InputReceiver(ProcessInfoList process);

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
