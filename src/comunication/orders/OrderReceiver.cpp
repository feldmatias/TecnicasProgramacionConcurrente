#include "OrderReceiver.h"

OrderReceiver::OrderReceiver() = default;

OrderReceiver::~OrderReceiver() = default;

Order OrderReceiver::receiveOrders(const std::string& order) {
    return protocol.receiveOrder(order);
}
