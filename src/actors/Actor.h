

#ifndef PRIMAVERA_CONCURRENTE_ACTOR_H
#define PRIMAVERA_CONCURRENTE_ACTOR_H


#include <string>
#include "ActorInfo.h"
#include "../concurrency/Runnable.h"

class Actor : public Runnable {
protected:
    std::string name;

public:
    explicit Actor(const ActorInfo& info);

    ~Actor() override;
};


#endif //PRIMAVERA_CONCURRENTE_ACTOR_H
