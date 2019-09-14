

#ifndef PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H


#include "../DataReceiver.h"
#include "OrderProtocol.h"

class OrderReceiver {
private:
    OrderProtocol protocol;

public:
    /**
     * Create a receiver.
     */
    explicit OrderReceiver();

    /**
     * Destructor.
     */
    ~OrderReceiver();

    /**
     * Receive all orders.
     */
    Order receiveOrders(const std::string& order);
};


#endif //PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
