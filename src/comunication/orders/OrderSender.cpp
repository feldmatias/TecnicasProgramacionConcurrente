

#include "OrderSender.h"
#include "../../concurrency/Fifo.h"
#include "../../utils/file/WriteOnlyFile.h"

OrderSender::OrderSender() = default;

OrderSender::~OrderSender() = default;

void OrderSender::sendOrder(const std::string& receiver, const Order& order) const {
    std::string info = protocol.sendOrder(order);
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(info);
}
