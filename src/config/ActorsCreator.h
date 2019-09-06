

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H


#include <vector>
#include "ActorsConfig.h"

class ActorsCreator {
private:
    ActorsConfig config;

public:
    ActorsCreator();

    ~ActorsCreator();

    bool createActors() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
