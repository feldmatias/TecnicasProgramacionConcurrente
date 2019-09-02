

#ifndef PRIMAVERA_CONCURRENTE_ACTOR_H
#define PRIMAVERA_CONCURRENTE_ACTOR_H


#include <string>
#include "ActorInfo.h"

class Actor {
protected:
    std::string name;

public:
    explicit Actor(ActorInfo& info);

    virtual ~Actor();
};


#endif //PRIMAVERA_CONCURRENTE_ACTOR_H
