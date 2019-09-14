#include "Producer.h"

#include <utility>
#include "Actor.h"
#include "DistributionCenter.h"
#include "../utils/common/Random.h"
#include "../logger/Logger.h"
#include "../utils/common/TimeSimulator.h"

#define PRODUCER_NAME std::string("Productor")

std::string Producer::getName(int name) {
    return PRODUCER_NAME + std::to_string(name);
}

Producer::Producer(std::string name) :
    Actor(std::move(name)) {
    boxSize = config.producersBoxSize();
}

void Producer::receiveData(Data data) {
    collectFlower();
    if (stock.countFlowers() == boxSize) {
        sendFlowers();
    }
    TimeSimulator::simulate();
}

void Producer::collectFlower() {
    std::vector<FlowerType> flowerTypes = FlowerType::all();

    FlowerType type = flowerTypes[Random::generate(flowerTypes.size())];
    stock.addFlower(Flower(actorName, type));
}

void Producer::sendFlowers() {
    int centerNumber = Random::generate(config.numberOfDistributionCenters());
    std::string center = DistributionCenter::getName(centerNumber);

    FlowerList flowers = stock.getAllFlowers();
    flowerSender.sendFlowers(center, flowers);
    Logger::sendTransaction(FlowerTransaction(actorName, center, flowers));
}

Producer::~Producer() = default;
