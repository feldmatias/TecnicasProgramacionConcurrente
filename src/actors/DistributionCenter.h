

#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"
#include "../concurrency/Fifo.h"
#include "../flower/FlowersBox.h"

class DistributionCenter : public Actor {
    //Fifo storage;
public:
    explicit DistributionCenter(const ActorInfo& info);

    ~DistributionCenter() override;

    void doWork() override;

    void finish() override;

    FlowersBox getFlowersBox();
};


#endif //PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
