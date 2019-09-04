#include "FlowerReceiver.h"

FlowerReceiver::FlowerReceiver(const std::string& receiver) :
    fifo(receiver) {
}

FlowerList FlowerReceiver::receiveFlowers() {
    FlowerList list;

    while (fifo.hasData()) {
        list.splice(list.end(), protocol.receiveFlowers(fifo.getLine()));
    }

    return list;
}

FlowerReceiver::~FlowerReceiver() = default;
