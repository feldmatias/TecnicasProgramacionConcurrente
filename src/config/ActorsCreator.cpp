

#include "ActorsCreator.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../../config/ConfigFiles.h"
#include "../utils/csv/CsvLine.h"

template <class T>
std::vector<T> initializeActors(const std::string& configFile) {
    std::vector<T> actors;
    ReadOnlyFile file(configFile);

    while(file.hasMoreData()) {
        CsvLine data(file.getLine());
        T actor(data.getNext());
        actors.push_back(actor);
    }

    return actors;
}

ActorsCreator::ActorsCreator() {
    producers = initializeActors<Producer>(PRODUCERS_CONFIG);
    distributionCenters = initializeActors<DistributionCenter>(DISTRIBUTION_CENTERS_CONFIG);
    pointsOfSale = initializeActors<PointOfSale>(POINTS_OF_SALE_CONFIG);
}

ActorsCreator::~ActorsCreator() = default;

std::vector<Producer> ActorsCreator::getProducers() const {
    return producers;
}

std::vector<DistributionCenter> ActorsCreator::getDistributionCenters() const {
    return distributionCenters;
}

std::vector<PointOfSale> ActorsCreator::getPointsOfSale() const {
    return pointsOfSale;
}
