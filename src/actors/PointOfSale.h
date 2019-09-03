

#ifndef PRIMAVERA_CONCURRENTE_POINTOFSALE_H
#define PRIMAVERA_CONCURRENTE_POINTOFSALE_H


#include <string>
#include "Actor.h"

class PointOfSale : Actor {

public:
    explicit PointOfSale(const ActorInfo& info);

    ~PointOfSale() override;
};


#endif //PRIMAVERA_CONCURRENTE_POINTOFSALE_H
