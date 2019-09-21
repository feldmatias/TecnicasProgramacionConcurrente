
#include "ActorsCreator.h"
#include "../actors/Producer.h"
#include "../actors/DistributionCenter.h"
#include "../actors/PointOfSale.h"
#include "../concurrency/Process.h"

template <class T>
ProcessInfoList createActorsFromConfig(int count) {
    ProcessInfoList process;

    for (int i = 0; i < count; i++) {
        T actor(T::getName(i));
        ProcessInfo info = Process::create(actor);
        if (info.isChildProcess()) {
            return ProcessInfoList();
        } else {
            process.push_back(info);
        }
    }
    return process;
}

ActorsCreator::ActorsCreator() = default;

ActorsCreator::~ActorsCreator() = default;

ProcessInfoList ActorsCreator::createActors() const {
    ProcessInfoList producers = createActorsFromConfig<Producer>(config.numberOfProducers());
    if (producers.empty()) {
        return producers;
    }

    ProcessInfoList centers = createActorsFromConfig<DistributionCenter>(config.numberOfDistributionCenters());
    if (centers.empty()) {
        return centers;
    }

    ProcessInfoList pointsOfSale = createActorsFromConfig<PointOfSale>(config.numberOfPointsOfSale());
    if (pointsOfSale.empty()) {
        return pointsOfSale;
    }

    ProcessInfoList process;
    process.splice(process.end(), producers);
    process.splice(process.end(), centers);
    process.splice(process.end(), pointsOfSale);
    return process;
}
