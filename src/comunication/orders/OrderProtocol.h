

#ifndef PRIMAVERA_CONCURRENTE_ORDERPROTOCOL_H
#define PRIMAVERA_CONCURRENTE_ORDERPROTOCOL_H


#include "../../orders/Order.h"

class OrderProtocol {
public:
    /**
     * Constructor.
     */
    OrderProtocol();

    /**
     * Destructor.
     */
    ~OrderProtocol();

    /**
     * Convert an order to a string.
     */
    std::string sendOrder(const Order &order) const;

    /**
     * Convert string to an order.
     */
    Order receiveOrder(const std::string &data) const;
};


#endif //PRIMAVERA_CONCURRENTE_ORDERPROTOCOL_H
