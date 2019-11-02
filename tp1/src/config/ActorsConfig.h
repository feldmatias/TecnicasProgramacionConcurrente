

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H
#define PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H

#include "Config.h"

class ActorsConfig : public Config {
public:
    /**
     * Constructor.
     */
    ActorsConfig();

    /**
     * Destructor.
     */
    ~ActorsConfig() override;

    /**
     * Get number of producers.
     */
    int numberOfProducers() const;

    /**
     * Get producer's box size.
     */
    int producersBoxSize() const;

    /**
     * Get number of distribution centers.
     */
    int numberOfDistributionCenters() const;

    /**
     * Get distribution center's box size.
     */
    int centersBoxSize() const;

    /**
     * Get number of points of sale.
     */
    int numberOfPointsOfSale() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H
