

#ifndef PRIMAVERA_CONCURRENTE_ORDERSENDER_H
#define PRIMAVERA_CONCURRENTE_ORDERSENDER_H


#include "OrderProtocol.h"

class OrderSender {
private:
    OrderProtocol protocol;

public:
    OrderSender();

    ~OrderSender();

    void sendOrder(const std::string& receiver, const Order& order) const;
};


#endif //PRIMAVERA_CONCURRENTE_ORDERSENDER_H
