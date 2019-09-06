#include "Producer.h"

#include <utility>
#include "Actor.h"
#include "DistributionCenter.h"

#define PRODUCER_NAME std::string("Producer")

std::string Producer::getName(int name) {
    return PRODUCER_NAME + std::to_string(name);
}

Producer::Producer(std::string name) :
    Actor(std::move(name)) {
    boxSize = config.producersBoxSize();
}

void Producer::doWork() {
    collectFlower();
    if (stock.countFlowers() == boxSize) {
        sendFlowers();
    }
}

void Producer::finish() {
    // TODO: implement this
}

void Producer::collectFlower() {
    srand(time(NULL));
    std::vector<FlowerType> flowerTypes = FlowerType::all();

    FlowerType type = flowerTypes[rand() % flowerTypes.size()];
    stock.addFlower(Flower(name, type));
}

void Producer::sendFlowers() {
    srand(time(NULL));
    int number = rand() % config.numberOfDistributionCenters();
    std::string center = DistributionCenter::getName(number);
    flowerSender.sendFlowers(center, stock.getAllFlowers());
}

Producer::~Producer() = default;
