

#include "OrderReceiver.h"

OrderReceiver::OrderReceiver(const std::string& receiver) :
    DataReceiver(receiver) {
}

OrderList OrderReceiver::receiveOrders() {
    initializeReceiver();

    OrderList list;
    while (true) {
        std::string line = receiveNext();
        if (line.empty()) {
            break;
        }
        list.push_back(protocol.receiveOrder(line));
    }

    return list;
}

OrderReceiver::~OrderReceiver() = default;
