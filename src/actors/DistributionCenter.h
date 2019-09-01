

#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"

class DistributionCenter : public Actor {

public:
    DistributionCenter(std::string&& name);

    ~DistributionCenter() override;
};


#endif //PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
