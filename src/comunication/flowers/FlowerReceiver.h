

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
    explicit FlowerReceiver(const std::string& receiver);

    ~FlowerReceiver() override;

    FlowerList receiveFlowers();

    FlowerTransactionList receiveFlowerTransactions();

};


#endif //PRIMAVERA_CONCURRENTE_FLOWERRECEIVER_H
