

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
#define PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H


#include <vector>
#include "../config/ActorsConfig.h"

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
     * Returns true if an actor was created (child process), false otherwise.
     */
    bool createActors() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCREATOR_H
