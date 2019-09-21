#ifndef PRIMAVERA_CONCURRENTE_PROCESS_H
#define PRIMAVERA_CONCURRENTE_PROCESS_H

#include "Runnable.h"
#include "../../comunication/DataReceiver.h"
#include "ProcessInfo.h"
#include <list>

#define EXIT "EXIT"

class Process {
private:
    DataReceiver receiver;
    Runnable& runnable;

public:
    /**
     * Create a child process.
     */
     static ProcessInfo create(Runnable& runnable);

    /**
     * Create a process with a runnable.
     */
    explicit Process(Runnable& runnable);

    /**
     * Destructor.
     */
    ~Process();

    /**
     * Start the process.
     */
    void run();
};


#endif //PRIMAVERA_CONCURRENTE_PROCESS_H
