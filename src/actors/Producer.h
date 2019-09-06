

#ifndef PRIMAVERA_CONCURRENTE_PRODUCER_H
#define PRIMAVERA_CONCURRENTE_PRODUCER_H


#include <string>
#include "Actor.h"
#include "../config/ActorsCreator.h"
#include "../concurrency/Fifo.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../../config/ConfigFiles.h"
#include "../flower/FlowerStock.h"
#include "../comunication/FlowerSender.h"
#include <unistd.h>
#include <vector>

class Producer : public Actor {
private:
    FlowerStock stock;
    FlowerSender flowerSender;

    void collectFlower();

    void sendFlowers();

public:
    static std::string getName(int name);

    explicit Producer(int name);

    ~Producer() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_PRODUCER_H
