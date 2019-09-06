

#ifndef PRIMAVERA_CONCURRENTE_POINTOFSALE_H
#define PRIMAVERA_CONCURRENTE_POINTOFSALE_H


#include <string>
#include "Actor.h"

class PointOfSale : public Actor {

public:
    static std::string getName(int name);

    explicit PointOfSale(int name);

    ~PointOfSale() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_POINTOFSALE_H
