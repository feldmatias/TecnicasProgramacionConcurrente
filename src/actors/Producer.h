

#ifndef PRIMAVERA_CONCURRENTE_PRODUCER_H
#define PRIMAVERA_CONCURRENTE_PRODUCER_H


#include <string>
#include "Actor.h"
#include "../process_creators/ActorsCreator.h"
#include "../concurrency/Fifo.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../../config/ConfigFiles.h"
#include "../comunication/flowers/FlowerSender.h"
#include <unistd.h>
#include <vector>

class Producer : public Actor {
private:
    FlowerSender flowerSender;

    int boxSize;

    void collectFlower();

    void sendFlowers();

public:
    static std::string getName(int name);

    explicit Producer(std::string name);

    ~Producer() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_PRODUCER_H
