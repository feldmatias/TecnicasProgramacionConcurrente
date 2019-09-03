

#ifndef PRIMAVERA_CONCURRENTE_PRODUCER_H
#define PRIMAVERA_CONCURRENTE_PRODUCER_H


#include <string>
#include "Actor.h"

class Producer : public Actor {

public:
    explicit Producer(const ActorInfo& info);

    ~Producer() override;

    void doWork() override;

    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_PRODUCER_H
