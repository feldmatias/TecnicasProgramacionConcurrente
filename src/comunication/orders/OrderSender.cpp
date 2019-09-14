#include "OrderSender.h"

OrderSender::OrderSender() = default;

OrderSender::~OrderSender() = default;

void OrderSender::sendClient(const std::string& receiver, const Order& order) const {
    std::string info = protocol.sendOrder(order);
    DataSender::sendData(receiver, CLIENT_DATA, info);
}
