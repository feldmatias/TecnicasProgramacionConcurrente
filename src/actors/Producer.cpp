

#include "Producer.h"

const int BOX_SIZE = 10;

Producer::Producer(const ActorInfo& info) :
    Actor(info) {
}

void Producer::doWork() {
    FlowersBox box = create_box();
    send_to_distribution_center(box);
}

void Producer::finish() {
    // TODO: implement this
}

FlowersBox Producer::create_box() {
    // to review random generator
    srand(getpid() + time(NULL));
    int roses = rand() % BOX_SIZE + 1;
    int tulips = BOX_SIZE - roses;
    return FlowersBox(name, roses, tulips);
}

void Producer::send_to_distribution_center(FlowersBox box) {
    ActorsCreator actorsCreator;
    std::vector<ActorInfo> distribution_centers =  actorsCreator.getDistributionCenters();
    int number_of_center = rand() % distribution_centers.size();
    WriteOnlyFile file(distribution_centers[number_of_center].getName() + FIFO_EXTENSION);
    file.writeLine(box.getProducer() + "," + std::to_string(box.getRoses()) + "," + std::to_string(box.getTulips()));
}

Producer::~Producer() = default;
