

#ifndef PRIMAVERA_CONCURRENTE_PRODUCER_H
#define PRIMAVERA_CONCURRENTE_PRODUCER_H


#include <string>
#include "Actor.h"
#include "../comunication/flowers/FlowerSender.h"

class Producer : public Actor {
private:
    FlowerSender flowerSender;

    int boxSize;

    /**
     * Collect a new flower.
     */
    void collectFlower();

    /**
     * Send flowers to a distribution center.
     */
    void sendFlowers();

public:
    /**
     * Convert an index to a producer name.
     */
    static std::string getName(int name);

    /**
     * Create a producer with a name.
     */
    explicit Producer(std::string name);

    /**
     * Destructor.
     */
    ~Producer() override;

    /**
     * Do producer's work.
     */
    void doWork(Data data) override;

    /**
      * If receives data from other process.
      */
    bool receivesData() override {
        return false;
    }

};


#endif //PRIMAVERA_CONCURRENTE_PRODUCER_H
