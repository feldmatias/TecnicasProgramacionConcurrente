

#ifndef PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H


#include "../DataReceiver.h"
#include "OrderProtocol.h"

class OrderReceiver : public DataReceiver {
private:
    OrderProtocol protocol;

public:
    explicit OrderReceiver(const std::string& receiver);

    ~OrderReceiver() override;

    OrderList receiveOrders();
};


#endif //PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
