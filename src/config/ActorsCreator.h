

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H


#include <vector>
#include "../actors/Producer.h"
#include "../actors/DistributionCenter.h"
#include "../actors/PointOfSale.h"

class ActorsCreator {
private:
    std::vector<Producer> producers;
    std::vector<DistributionCenter> distributionCenters;
    std::vector<PointOfSale> pointsOfSale;

public:
    ActorsCreator();

    ~ActorsCreator();

    std::vector<Producer> getProducers() const;

    std::vector<DistributionCenter> getDistributionCenters() const;

    std::vector<PointOfSale> getPointsOfSale() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
