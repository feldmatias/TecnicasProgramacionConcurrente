#ifndef PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H
#define PRIMAVERA_CONCURRENTE_INPUTRECEIVER_H

#include "../../concurrency/Process.h"

#define STATISTICS_CHAR 's'
#define EXIT_CHAR 'q'

class InputReceiver {
private:
    ProcessNames processNames;

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
    InputReceiver(ProcessNames processNames);

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
