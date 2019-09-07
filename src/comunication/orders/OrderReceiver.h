

#ifndef PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H


#include "../DataReceiver.h"
#include "OrderProtocol.h"

class OrderReceiver : public DataReceiver {
private:
    OrderProtocol protocol;

public:
    /**
     * Create a receiver.
     */
    explicit OrderReceiver(const std::string& receiver);

    /**
     * Destructor.
     */
    ~OrderReceiver() override;

    /**
     * Receive all orders.
     */
    OrderList receiveOrders();
};


#endif //PRIMAVERA_CONCURRENTE_ORDERRECEIVER_H
