

#ifndef PRIMAVERA_CONCURRENTE_POINTOFSALE_H
#define PRIMAVERA_CONCURRENTE_POINTOFSALE_H


#include <string>
#include "Actor.h"
#include "../comunication/flowers/FlowerReceiver.h"

class PointOfSale : public Actor {
private:
    FlowerReceiver flowerReceiver;

    void receiveFlowers();

public:
    static std::string getName(int name);

    explicit PointOfSale(const std::string& name);

    ~PointOfSale() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_POINTOFSALE_H
