

#include "SimulationConfig.h"
#include "../ConfigFiles.h"

SimulationConfig::SimulationConfig() : Config(SIMULATION_CONFIG) {
}

int SimulationConfig::simulationTime() const {
    return config.at("time_simulation");
}

SimulationConfig::~SimulationConfig() = default;
