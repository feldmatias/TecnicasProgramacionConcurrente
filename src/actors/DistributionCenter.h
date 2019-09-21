#ifndef PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
#define PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H


#include <string>
#include "Actor.h"
#include "../concurrency/fifos/Fifo.h"
#include "../comunication/flowers/FlowerReceiver.h"
#include "../comunication/flowers/FlowerSender.h"

class DistributionCenter : public Actor {
private:
    FlowerReceiver flowerReceiver;
    FlowerSender flowerSender;

    int boxSize;

    /**
     * Receive flowers from producers.
     */
    void receiveFlowers(const std::string& flowers);

    /**
     * Classify flowers by type.
     */
    void processFlowers();

    /**
     * Send flowers to a point of sale.
     */
    void sendFlowers(const FlowerType& type);

public:
    /**
     * Convert index to a distribution center name.
     */
    static std::string getName(int name);

    /**
     * Create a distribution center with a name.
     */
    explicit DistributionCenter(const std::string& name);

    /**
     * Destructor.
     */
    ~DistributionCenter() override;

    /**
     * Do distribution center's work.
     */
    void doWork(Data data) override;
};


#endif //PRIMAVERA_CONCURRENTE_DISTRIBUTIONCENTER_H
