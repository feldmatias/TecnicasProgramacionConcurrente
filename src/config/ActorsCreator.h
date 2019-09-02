

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H


#include <vector>
#include "../actors/ActorInfo.h"

class ActorsCreator {
private:
    std::vector<ActorInfo> producers;
    std::vector<ActorInfo> distributionCenters;
    std::vector<ActorInfo> pointsOfSale;

public:
    ActorsCreator();

    ~ActorsCreator();

    std::vector<ActorInfo> getProducers() const;

    std::vector<ActorInfo> getDistributionCenters() const;

    std::vector<ActorInfo> getPointsOfSale() const;

    bool createActors() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
