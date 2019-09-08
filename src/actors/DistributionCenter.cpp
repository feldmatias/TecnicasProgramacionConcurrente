#include "DistributionCenter.h"
#include "../utils/common/Random.h"
#include "PointOfSale.h"

#define CENTER_NAME std::string("DistributionCenter")

std::string DistributionCenter::getName(int name) {
    return CENTER_NAME + std::to_string(name);
}

DistributionCenter::DistributionCenter(const std::string& name) :
    Actor(name), flowerReceiver(name) {
    boxSize = config.centersBoxSize();
}

void DistributionCenter::doWork() {
    receiveFlowers();
    processFlowers();
}

void DistributionCenter::finish() {
    // TODO: implement this
}

void DistributionCenter::receiveFlowers() {
    FlowerList list = flowerReceiver.receiveFlowers();
    stock.addFlowers(list);
}

void DistributionCenter::processFlowers() {
    for (const FlowerType& type : FlowerType::all()) {
        if (stock.countFlowers(type) >= boxSize) {
            sendFlowers(type);
        }
    }
}

void DistributionCenter::sendFlowers(const FlowerType& type) {
    int salePointNumber = Random::generate(config.numberOfPointsOfSale());
    std::string salePoint = PointOfSale::getName(salePointNumber);
    flowerSender.sendFlowers(salePoint, stock.getFlowers(type, boxSize));
}

DistributionCenter::~DistributionCenter() = default;
