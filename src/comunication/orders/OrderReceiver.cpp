#include "OrderReceiver.h"

OrderReceiver::OrderReceiver() = default;

OrderReceiver::~OrderReceiver() = default;

Order OrderReceiver::receiveOrder(const std::string& order) {
    return protocol.receiveOrder(order);
}
