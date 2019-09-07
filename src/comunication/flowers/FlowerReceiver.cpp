#include "FlowerReceiver.h"

FlowerReceiver::FlowerReceiver(const std::string& receiver) :
    DataReceiver(receiver) {
}

FlowerList FlowerReceiver::receiveFlowers() {
    initializeReceiver();

    FlowerList list;
    while (true) {
        std::string line = receiveNext();
        if (line.empty()) {
            break;
        }
        list.splice(list.end(), protocol.receiveFlowers(line));
    }

    return list;
}

FlowerTransactionList FlowerReceiver::receiveFlowerTransactions() {
    initializeReceiver();

    FlowerTransactionList list;
    while (true) {
        std::string line = receiveNext();
        if (line.empty()) {
            break;
        }
        list.push_back(protocol.receiveFlowersTransaction(line));
    }

    return list;
}

FlowerReceiver::~FlowerReceiver() = default;
