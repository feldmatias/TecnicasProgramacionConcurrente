#include "FlowerReceiver.h"

FlowerReceiver::FlowerReceiver()= default;

FlowerList FlowerReceiver::receiveFlowers(const std::string& flowers) {
    return protocol.receiveFlowers(flowers);
}

FlowerTransaction FlowerReceiver::receiveFlowerTransaction(const std::string& transaction) {
    return protocol.receiveFlowersTransaction(transaction);
}

FlowerReceiver::~FlowerReceiver() = default;
