#include "FlowerReceiver.h"
#include "../../utils/file/WriteOnlyFile.h"

#define END_OF_BLOCK "END_OF_BLOCK"

FlowerReceiver::FlowerReceiver(const std::string& receiver) :
    fifo(receiver), receiver(receiver) {
}

FlowerList FlowerReceiver::receiveFlowers() {
    initializeReceiver();

    FlowerList list;
    while (true) {
        std::string line = fifo.getLine();
        if (line == END_OF_BLOCK) {
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
        std::string line = fifo.getLine();
        if (line == END_OF_BLOCK) {
            break;
        }
        list.push_back(protocol.receiveFlowersTransaction(line));
    }

    return list;
}

void FlowerReceiver::initializeReceiver() {
    // This allows to know if Fifo has new data or not.
    // Without this, there is no way to know if fifo has data, and getline() blocks
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(END_OF_BLOCK);
}

FlowerReceiver::~FlowerReceiver() = default;
