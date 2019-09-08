

#ifndef PRIMAVERA_CONCURRENTE_ORDERSENDER_H
#define PRIMAVERA_CONCURRENTE_ORDERSENDER_H


#include "OrderProtocol.h"
#include "../DataSender.h"

class OrderSender : public DataSender {
private:
    OrderProtocol protocol;

public:
    /**
     * Constructor.
     */
    OrderSender();

    /**
     * Destructor.
     */
    ~OrderSender() override;

    /**
     * Send an order to a receiver.
     */
    void sendOrder(const std::string& receiver, const Order& order) const;
};


#endif //PRIMAVERA_CONCURRENTE_ORDERSENDER_H
