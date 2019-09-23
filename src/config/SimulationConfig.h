

#ifndef PRIMAVERA_CONCURRENTE_SIMULATIONCONFIG_H
#define PRIMAVERA_CONCURRENTE_SIMULATIONCONFIG_H


#include "Config.h"

class SimulationConfig : public Config {
public:
    /**
     * Constructor.
     */
    SimulationConfig();

    /**
     * Destructor.
     */
    ~SimulationConfig() override;

    /**
     * Get simulation time.
     */
    int simulationTime() const;
};


#endif //PRIMAVERA_CONCURRENTE_SIMULATIONCONFIG_H
