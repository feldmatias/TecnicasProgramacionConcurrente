

#ifndef PRIMAVERA_CONCURRENTE_DATARECEIVER_H
#define PRIMAVERA_CONCURRENTE_DATARECEIVER_H


#include "../concurrency/Fifo.h"

class DataReceiver {
private:
    Fifo fifo;

protected:
    std::string receiver;

    /**
     * Initialize the receiver to start receiving.
     */
    void initializeReceiver();

public:
    /**
     * Create a receiver.
     */
    explicit DataReceiver(const std::string& receiver);

    /**
     * Destructor.
     */
    virtual ~DataReceiver();

    /**
     * Receive next data sent.
     */
    std::string receiveNext();
};


#endif //PRIMAVERA_CONCURRENTE_DATARECEIVER_H
