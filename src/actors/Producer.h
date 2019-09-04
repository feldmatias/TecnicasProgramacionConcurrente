

#ifndef PRIMAVERA_CONCURRENTE_PRODUCER_H
#define PRIMAVERA_CONCURRENTE_PRODUCER_H


#include <string>
#include "Actor.h"
#include "../config/ActorsCreator.h"
#include "../concurrency/Fifo.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../flower/FlowersBox.h"
#include "../flower/FlowersBox.h"
#include "../../config/ConfigFiles.h"
#include <unistd.h>
#include <vector>

class Producer : public Actor {

public:
    explicit Producer(const ActorInfo& info);

    ~Producer() override;

    void doWork() override;

    void finish() override;

    FlowersBox create_box();

    void send_to_distribution_center(FlowersBox box);
};


#endif //PRIMAVERA_CONCURRENTE_PRODUCER_H
