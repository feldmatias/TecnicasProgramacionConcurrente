

#ifndef PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H


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
    Order receiveOrder(const std::string &order);
};


#endif //PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
