
#include "ActorsCreator.h"
#include "../actors/Producer.h"
#include "../actors/DistributionCenter.h"
#include "../actors/PointOfSale.h"
#include "../concurrency/process/DataReceiverProcess.h"
#include "../concurrency/process/DataSenderProcess.h"

template <class T>
ProcessInfoList createActorsFromConfig(int count, bool receivesData) {
    ProcessInfoList process;

    for (int i = 0; i < count; i++) {
        T actor(T::getName(i));

        ProcessInfo info = receivesData ? DataReceiverProcess::create(actor) : DataSenderProcess::create(actor);

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
    ProcessInfoList centers = createActorsFromConfig<DistributionCenter>(config.numberOfDistributionCenters(), true);
    if (centers.empty()) {
        return centers;
    }

    ProcessInfoList pointsOfSale = createActorsFromConfig<PointOfSale>(config.numberOfPointsOfSale(), true);
    if (pointsOfSale.empty()) {
        return pointsOfSale;
    }

    ProcessInfoList producers = createActorsFromConfig<Producer>(config.numberOfProducers(), false);
    if (producers.empty()) {
        return producers;
    }

    ProcessInfoList process;
    process.splice(process.end(), producers);
    process.splice(process.end(), centers);
    process.splice(process.end(), pointsOfSale);
    return process;
}
