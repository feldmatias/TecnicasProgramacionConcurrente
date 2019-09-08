#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"
#include "../concurrency/Fifo.h"
#include "../comunication/flowers/FlowerReceiver.h"
#include "../comunication/flowers/FlowerSender.h"

class DistributionCenter : public Actor {
private:
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
