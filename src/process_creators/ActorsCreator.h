

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H


#include <vector>
#include "../config/ActorsConfig.h"
#include "../concurrency/Process.h"

class ActorsCreator {
private:
    ActorsConfig config;

public:
    /**
     * Constructor.
     */
    ActorsCreator();

    /**
     * Destructor.
     */
    ~ActorsCreator();

    /**
     * Create producers, distribution centers and points of sale.
     * Returns empty list if an actor was created (child process), process infos otherwise.
     */
    ProcessInfoList createActors() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
