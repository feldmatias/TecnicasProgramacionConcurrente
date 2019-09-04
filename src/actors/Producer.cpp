
#include "Producer.h"

const int BOX_SIZE = 10;

Producer::Producer(const ActorInfo& info) :
    Actor(info) {
}

void Producer::doWork() {
    collect_flower();
    if (stock.countFlowers() == BOX_SIZE) {
        sendFlowers();
    }
}

void Producer::finish() {
    // TODO: implement this
}

void Producer::collect_flower() {
    srand(time(NULL));
    std::vector<FlowerType> flowerTypes = FlowerType::all();

    FlowerType type = flowerTypes[rand() % flowerTypes.size()];
    stock.addFlower(Flower(name, type));
}

void Producer::sendFlowers() {
    srand(time(NULL));
    ActorsCreator actorsCreator;
    std::vector<ActorInfo> distribution_centers =  actorsCreator.getDistributionCenters();
    int number_of_center = rand() % distribution_centers.size();
    std::string center = distribution_centers[number_of_center].getName();
    flowerSender.sendFlowers(center, stock.getAllFlowers());
}

Producer::~Producer() = default;
