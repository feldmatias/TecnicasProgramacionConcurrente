#include "FlowerSender.h"

FlowerSender::FlowerSender() = default;

FlowerSender::~FlowerSender() = default;

void FlowerSender::sendFlowers(const std::string &receiver, const FlowerList& flowers) const {
    std::string info = protocol.sendFlowers(flowers);
    sendData(receiver, info);
}

void FlowerSender::sendFlowerTransaction(const std::string& receiver, const FlowerTransaction& transaction) const {
    std::string info = protocol.sendFlowerTransaction(transaction);
    sendData(receiver, info);
}
