

#ifndef PRIMAVERA_CONCURRENTE_DATASENDERPROCESS_H
#define PRIMAVERA_CONCURRENTE_DATASENDERPROCESS_H


#include "Runnable.h"
#include "../signals/ExitSignalEventHandler.h"
#include "ProcessInfo.h"

class DataSenderProcess {
private:
    Runnable& runnable;
    ExitSignalEventHandler exitHandler;

public:
    /**
     * Create a child process.
     */
    static ProcessInfo create(Runnable& runnable);

    /**
     * Create a process with a runnable.
     */
    explicit DataSenderProcess(Runnable& runnable);

    /**
     * Destructor.
     */
    ~DataSenderProcess();

    /**
     * Start the process.
     */
    void run();
};


#endif //PRIMAVERA_CONCURRENTE_DATASENDERPROCESS_H
