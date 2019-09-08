

#ifndef PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H


#include "../../concurrency/Fifo.h"
#include "../../flower/Flower.h"
#include "FlowerProtocol.h"
#include "../DataReceiver.h"

class FlowerReceiver : public DataReceiver {
private:
    FlowerProtocol protocol;

public:
    /**
     * Create a receiver.
     */
    explicit FlowerReceiver(const std::string& receiver);

    /**
     * Destructor.
     */
    ~FlowerReceiver() override;

    /**
     * Receive all flowers.
     */
    FlowerList receiveFlowers();

    /**
     * Receive all transactions.
     */
    FlowerTransactionList receiveFlowerTransactions();

};


#endif //PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
