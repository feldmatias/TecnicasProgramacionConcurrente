

#include "FlowerSender.h"
#include "../../utils/file/WriteOnlyFile.h"
#include "../../concurrency/Fifo.h"

FlowerSender::FlowerSender() = default;

FlowerSender::~FlowerSender() = default;

void FlowerSender::sendFlowers(const std::string &receiver, const FlowerList& flowers) const {
    std::string info = protocol.sendFlowers(flowers);
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(info);
}
