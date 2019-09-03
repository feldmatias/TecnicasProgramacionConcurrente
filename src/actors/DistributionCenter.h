

#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"

class DistributionCenter : public Actor {

public:
    explicit DistributionCenter(const ActorInfo& info);

    ~DistributionCenter() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
