#include "Producer.h"
#include "Actor.h"
#include "DistributionCenter.h"

#define PRODUCER_NAME std::string("Producer")

const int BOX_SIZE = 10;

std::string Producer::getName(int name) {
    return PRODUCER_NAME + std::to_string(name);
}

Producer::Producer(int name) :
    Actor(getName(name)) {
}

void Producer::doWork() {
    collectFlower();
    if (stock.countFlowers() == BOX_SIZE) {
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
