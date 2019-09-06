#include "DistributionCenter.h"
#include "../utils/common/Random.h"
#include "PointOfSale.h"
#include "../logger/Logger.h"

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
    Logger::sendTransaction(FlowerTransaction(name, list));
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

    FlowerList flowers = stock.getFlowers(type, boxSize);
    flowerSender.sendFlowers(salePoint, flowers);
    Logger::sendTransaction(FlowerTransaction(name, salePoint, flowers));
}

DistributionCenter::~DistributionCenter() = default;
