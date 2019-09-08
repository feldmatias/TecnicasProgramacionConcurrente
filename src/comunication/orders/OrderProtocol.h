

#ifndef PRIMAVERA_CONCURRENTE_ORDERPROTOCOL_H
#define PRIMAVERA_CONCURRENTE_ORDERPROTOCOL_H


#include "../../orders/Order.h"

class OrderProtocol {
public:
    OrderProtocol();

    ~OrderProtocol();

    std::string sendOrder(const Order& order) const;

    Order receiveOrder(const std::string& data) const;
};


#endif //PRIMAVERA_CONCURRENTE_ORDERPROTOCOL_H
