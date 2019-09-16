#include "FlowerSender.h"

FlowerSender::FlowerSender() = default;

FlowerSender::~FlowerSender() = default;

void FlowerSender::sendFlowers(const std::string &receiver, const FlowerList& flowers) const {
    std::string info = protocol.sendFlowers(flowers);
    DataSender::sendData(receiver, FLOWERS_DATA, info);
}

void FlowerSender::sendFlowerTransaction(const std::string& receiver, const FlowerTransaction& transaction) const {
    std::string info = protocol.sendFlowerTransaction(transaction);
    DataSender::sendData(receiver, TRANSACTION_DATA, info);
}
