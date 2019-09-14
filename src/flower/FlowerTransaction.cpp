#include "FlowerTransaction.h"
#include "../orders/ClientGenerator.h"

#include <utility>

FlowerTransaction::FlowerTransaction(std::string sender, std::string receiver, FlowerList flowers) :
    sender(std::move(sender)), receiver(std::move(receiver)), flowers(std::move(flowers)) {
}

FlowerTransaction::FlowerTransaction(std::string receiver, FlowerList flowers) :
    receiver(std::move(receiver)), flowers(std::move(flowers)) {
}

FlowerTransaction::FlowerTransaction(std::string seller, const Order& client, FlowerList flowers) :
    sender(std::move(seller)), receiver(client.getClient()), flowers(std::move(flowers)) {
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

bool FlowerTransaction::isSell() const {
    return receiver.find(CLIENT_NAME) != std::string::npos || receiver.find(INTERNET_NAME) != std::string::npos;
}

FlowerTransaction::~FlowerTransaction() = default;
