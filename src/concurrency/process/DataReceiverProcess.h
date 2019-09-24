#ifndef PRIMAVERA_CONCURRENTE_DATARECEIVERPROCESS_H
#define PRIMAVERA_CONCURRENTE_DATARECEIVERPROCESS_H

#include "Runnable.h"
#include "../../comunication/DataReceiver.h"
#include "ProcessInfo.h"

#define EXIT "EXIT"

class DataReceiverProcess {
private:
    DataReceiver receiver;
    Runnable &runnable;

public:
    /**
     * Create a child process.
     */
    static ProcessInfo create(Runnable &runnable);

    /**
     * Create a process with a runnable.
     */
    explicit DataReceiverProcess(Runnable &runnable);

    /**
     * Destructor.
     */
    ~DataReceiverProcess();

    /**
     * Start the process.
     */
    void run();
};


#endif //PRIMAVERA_CONCURRENTE_DATARECEIVERPROCESS_H
