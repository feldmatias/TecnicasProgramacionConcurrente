
#include <unistd.h>
#include "ActorsCreator.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../../config/ConfigFiles.h"
#include "../utils/csv/CsvLine.h"
#include "../actors/Producer.h"
#include "../actors/DistributionCenter.h"
#include "../actors/PointOfSale.h"

std::vector<ActorInfo> initializeActors(const std::string& configFile) {
    std::vector<ActorInfo> actors;
    ReadOnlyFile file(configFile);

    while(file.hasMoreData()) {
        CsvLine data(file.getLine());
        ActorInfo actor(data.getNext());
        actors.push_back(actor);
    }

    return actors;
}

template <class T>
bool createActorsFromInfo(const std::vector<ActorInfo>& actors) {
    for (const ActorInfo& actorInfo : actors) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            T actor(actorInfo);
            sleep(1); // Todo: replace this with something
            return true;
        }
    }
    return false;
}

ActorsCreator::ActorsCreator() {
    producers = initializeActors(PRODUCERS_CONFIG);
    distributionCenters = initializeActors(DISTRIBUTION_CENTERS_CONFIG);
    pointsOfSale = initializeActors(POINTS_OF_SALE_CONFIG);
}

ActorsCreator::~ActorsCreator() = default;

std::vector<ActorInfo> ActorsCreator::getProducers() const {
    return producers;
}

std::vector<ActorInfo> ActorsCreator::getDistributionCenters() const {
    return distributionCenters;
}

std::vector<ActorInfo> ActorsCreator::getPointsOfSale() const {
    return pointsOfSale;
}

bool ActorsCreator::createActors() const {
    if (createActorsFromInfo<Producer>(producers)) {
        return true;
    }

    if (createActorsFromInfo<DistributionCenter>(distributionCenters)) {
        return true;
    }

    if (createActorsFromInfo<PointOfSale>(pointsOfSale)) {
        return true;
    }

    return false;
}
