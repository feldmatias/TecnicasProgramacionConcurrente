

#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"
#include "../concurrency/Fifo.h"
#include "../flower/FlowerStock.h"
#include "../comunication/FlowerReceiver.h"

class DistributionCenter : public Actor {
private:
    FlowerStock stock;
    FlowerReceiver flowerReceiver;

    void receiveFlowers();

public:
    static std::string getName(int name);

    explicit DistributionCenter(const std::string& name);

    ~DistributionCenter() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
