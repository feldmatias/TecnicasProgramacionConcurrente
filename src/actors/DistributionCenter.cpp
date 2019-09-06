#include "DistributionCenter.h"

#define CENTER_NAME std::string("DistributionCenter")

std::string DistributionCenter::getName(int name) {
    return CENTER_NAME + std::to_string(name);
}

DistributionCenter::DistributionCenter(int name) :
    Actor(getName(name)), flowerReceiver(getName(name)) {
}

void DistributionCenter::doWork() {
    receiveFlowers();

    // TODO: implement this
}

void DistributionCenter::finish() {
    // TODO: implement this
}

void DistributionCenter::receiveFlowers() {
    FlowerList list = flowerReceiver.receiveFlowers();
    stock.addFlowers(list);
}

DistributionCenter::~DistributionCenter() = default;
