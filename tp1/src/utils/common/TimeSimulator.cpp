

#include <thread>
#include "TimeSimulator.h"
#include "../../config/SimulationConfig.h"

void TimeSimulator::simulate() {
    SimulationConfig config;
    std::this_thread::sleep_for(std::chrono::milliseconds(config.simulationTime()));
}
