

#include "FlowerSender.h"
#include "../../utils/file/WriteOnlyFile.h"
#include "../../concurrency/Fifo.h"

void send(const std::string &receiver, const std::string &info) {
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(info);
}

FlowerSender::FlowerSender() = default;

FlowerSender::~FlowerSender() = default;

void FlowerSender::sendFlowers(const std::string &receiver, const FlowerList& flowers) const {
    std::string info = protocol.sendFlowers(flowers);
    send(receiver, info);
}

void FlowerSender::sendFlowerTransaction(const std::string& receiver, const FlowerTransaction& transaction) const {
    std::string info = protocol.sendFlowerTransaction(transaction);
    send(receiver, info);
}
