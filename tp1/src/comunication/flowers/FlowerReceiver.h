

#ifndef PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H

#include "../../flower/Flower.h"
#include "FlowerProtocol.h"

class FlowerReceiver {
private:
    FlowerProtocol protocol;

public:
    /**
     * Create a receiver.
     */
    explicit FlowerReceiver();

    /**
     * Destructor.
     */
    ~FlowerReceiver();

    /**
     * Receive all flowers.
     */
    FlowerList receiveFlowers(const std::string &flowers);

    /**
     * Receive a transaction.
     */
    FlowerTransaction receiveFlowerTransaction(const std::string &transaction);

};


#endif //PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
