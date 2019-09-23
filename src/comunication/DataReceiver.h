

#ifndef PRIMAVERA_CONCURRENTE_DATARECEIVER_H
#define PRIMAVERA_CONCURRENTE_DATARECEIVER_H


#include "../concurrency/fifos/Fifo.h"
#include "Data.h"

class DataReceiver {
private:
    Fifo fifo;

public:
    /**
     * Create a receiver.
     */
    explicit DataReceiver(const std::string& receiver);

    /**
     * Destructor.
     */
    ~DataReceiver();

    /**
     * Receive next data sent.
     */
    Data receiveNext();
};


#endif //PRIMAVERA_CONCURRENTE_DATARECEIVER_H
