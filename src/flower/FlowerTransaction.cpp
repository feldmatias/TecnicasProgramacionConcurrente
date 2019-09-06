#include "FlowerTransaction.h"

#include <utility>

FlowerTransaction::FlowerTransaction(std::string sender, std::string receiver, FlowerList flowers) :
    sender(std::move(sender)), receiver(std::move(receiver)), flowers(std::move(flowers)) {
}

FlowerTransaction::FlowerTransaction(std::string receiver, FlowerList flowers) :
    receiver(std::move(receiver)), flowers(std::move(flowers)) {
}

std::string FlowerTransaction::getSender() const {
    return sender;
}

std::string FlowerTransaction::getReceiver() const {
    return receiver;
}

FlowerList FlowerTransaction::getFlowers() const {
    return flowers;
}

bool FlowerTransaction::hasSender() const {
    return !sender.empty();
}

FlowerTransaction::~FlowerTransaction() = default;
