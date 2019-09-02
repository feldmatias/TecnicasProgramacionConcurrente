

#include "ActorsCreator.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../../config/ConfigFiles.h"
#include "../utils/csv/CsvLine.h"

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
