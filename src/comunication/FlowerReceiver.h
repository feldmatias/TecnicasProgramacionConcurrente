

#ifndef PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H


#include "../concurrency/Fifo.h"
#include "../flower/Flower.h"
#include "FlowerProtocol.h"

class FlowerReceiver {
private:
    Fifo fifo;
    FlowerProtocol protocol;

public:
    explicit FlowerReceiver(const std::string& receiver);

    ~FlowerReceiver();

    FlowerList receiveFlowers();

};


#endif //PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
