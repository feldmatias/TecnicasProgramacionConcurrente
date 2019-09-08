

#ifndef PRIMAVERA_CONCURRENTE_DATARECEIVER_H
#define PRIMAVERA_CONCURRENTE_DATARECEIVER_H


#include "../concurrency/Fifo.h"

class DataReceiver {
private:
    Fifo fifo;

protected:
    std::string receiver;

    void initializeReceiver();

public:
    explicit DataReceiver(const std::string& receiver);

    virtual ~DataReceiver();

    std::string receiveNext();
};


#endif //PRIMAVERA_CONCURRENTE_DATARECEIVER_H
