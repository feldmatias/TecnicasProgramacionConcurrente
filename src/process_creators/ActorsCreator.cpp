
#include <unistd.h>
#include "ActorsCreator.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../utils/csv/CsvLine.h"
#include "../actors/Producer.h"
#include "../actors/DistributionCenter.h"
#include "../actors/PointOfSale.h"
#include "../concurrency/Process.h"

template <class T>
bool createActorsFromConfig(int count) {
    for (int i = 0; i < count; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            T actor(T::getName(i));
            Process process(actor);
            process.run();
            return true;
        }
    }
    return false;
}

ActorsCreator::ActorsCreator() = default;

ActorsCreator::~ActorsCreator() = default;

bool ActorsCreator::createActors() const {
    if (createActorsFromConfig<Producer>(config.numberOfProducers())) {
        return true;
    }

    if (createActorsFromConfig<DistributionCenter>(config.numberOfDistributionCenters())) {
        return true;
    }

    if (createActorsFromConfig<PointOfSale>(config.numberOfPointsOfSale())) {
        return true;
    }

    return false;
}
