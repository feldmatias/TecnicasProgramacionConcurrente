#include "DistributionCenter.h"

DistributionCenter::DistributionCenter(const ActorInfo& info) :
    Actor(info), flowerReceiver(info.getName()) {
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
