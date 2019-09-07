

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H
#define PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H

#include "Config.h"

class ActorsConfig : public Config {
public:
    ActorsConfig();

    ~ActorsConfig() override;

    int numberOfProducers() const;

    int producersBoxSize() const;

    int numberOfDistributionCenters() const;

    int centersBoxSize() const;

    int numberOfPointsOfSale() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H
