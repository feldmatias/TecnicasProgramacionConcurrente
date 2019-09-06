#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"
#include "../concurrency/Fifo.h"
#include "../flower/FlowerStock.h"
#include "../comunication/FlowerReceiver.h"
#include "../comunication/FlowerSender.h"

class DistributionCenter : public Actor {
private:
    FlowerStock stock;
    FlowerReceiver flowerReceiver;
    FlowerSender flowerSender;

    int boxSize;

    void receiveFlowers();

    void processFlowers();

    void sendFlowers(const FlowerType& type);

public:
    static std::string getName(int name);

    explicit DistributionCenter(const std::string& name);

    ~DistributionCenter() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
