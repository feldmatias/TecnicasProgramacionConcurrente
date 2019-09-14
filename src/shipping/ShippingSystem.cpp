

#include <iostream>
#include "ShippingSystem.h"
#include "../logger/Logger.h"
#include "../comunication/flowers/FlowerSender.h"

ShippingSystem::ShippingSystem() = default;

ShippingSystem::~ShippingSystem() = default;

std::string ShippingSystem::name() {
    return SHIPPING_SYSTEM;
}

void ShippingSystem::receiveData(Data data) {
    FlowerTransaction transaction = receiver.receiveFlowerTransaction(data.getData());
    std::cout << "SHIPPING SYSTEM" << std::endl;
}

void ShippingSystem::sendTransaction(const FlowerTransaction& transaction) {
    FlowerSender sender;
    sender.sendFlowerTransaction(SHIPPING_SYSTEM, transaction);
}
