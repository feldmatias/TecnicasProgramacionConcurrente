#ifndef PRIMAVERA_CONCURRENTE_PROCESS_H
#define PRIMAVERA_CONCURRENTE_PROCESS_H

#include "Runnable.h"
#include "../comunication/DataReceiver.h"
#include <list>

#define EXIT "EXIT"

typedef std::list<std::string> ProcessNames;

class Process {
private:
    DataReceiver receiver;
    Runnable& runnable;

public:
    /**
     * Create a child process.
     * Returns true if the process was created(child process), false otherwise.
     */
     static bool create(Runnable& runnable);

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
