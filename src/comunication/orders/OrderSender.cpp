#include "OrderSender.h"

OrderSender::OrderSender() = default;

OrderSender::~OrderSender() = default;

void OrderSender::sendOrder(const std::string& receiver, const Order& order) const {
    std::string info = protocol.sendOrder(order);
    DataSender::sendData(receiver, ORDER_DATA, info);
}
