

#ifndef PRIMAVERA_CONCURRENTE_ORDERSENDER_H
#define PRIMAVERA_CONCURRENTE_ORDERSENDER_H


#include "OrderProtocol.h"

#define CLIENT_DATA "client"
#define INTERNET_ORDER_DATA "internet"

class OrderSender {
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
    ~OrderSender();

    /**
     * Send a client to a receiver.
     */
    void sendClient(const std::string &receiver, const Order &order) const;

    /**
     * Send an internet order to a receiver.
     */
    void sendInternetOrder(const std::string &receiver, const Order &order) const;
};


#endif //PRIMAVERA_CONCURRENTE_ORDERSENDER_H
