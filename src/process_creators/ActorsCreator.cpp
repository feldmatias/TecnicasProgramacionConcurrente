
#include <unistd.h>
#include "ActorsCreator.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../utils/csv/CsvLine.h"
#include "../actors/Producer.h"
#include "../actors/DistributionCenter.h"
#include "../actors/PointOfSale.h"
#include "../concurrency/Process.h"

template <class T>
ProcessNames createActorsFromConfig(int count) {
    ProcessNames processNames;

    for (int i = 0; i < count; i++) {
        std::string name = T::getName(i);
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            T actor(name);
            Process process(actor);
            process.run();
            return ProcessNames();
        } else {
            processNames.push_back(name);
        }
    }
    return processNames;
}

ActorsCreator::ActorsCreator() = default;

ActorsCreator::~ActorsCreator() = default;

ProcessNames ActorsCreator::createActors() const {
    ProcessNames producers = createActorsFromConfig<Producer>(config.numberOfProducers());
    if (producers.empty()) {
        return producers;
    }

    ProcessNames centers = createActorsFromConfig<DistributionCenter>(config.numberOfDistributionCenters());
    if (centers.empty()) {
        return centers;
    }

    ProcessNames pointsOfSale = createActorsFromConfig<PointOfSale>(config.numberOfPointsOfSale());
    if (pointsOfSale.empty()) {
        return pointsOfSale;
    }

    ProcessNames processNames;
    processNames.splice(processNames.end(), producers);
    processNames.splice(processNames.end(), centers);
    processNames.splice(processNames.end(), pointsOfSale);
    return processNames;
}
