

#ifndef PRIMAVERA_CONCURRENTE_ACTOR_H
#define PRIMAVERA_CONCURRENTE_ACTOR_H


#include <string>
#include "../concurrency/Runnable.h"
#include "../config/ActorsConfig.h"
#include "../flower/FlowerStock.h"

class Actor : public Runnable {
protected:
    std::string name;
    FlowerStock stock;
    ActorsConfig config;

public:
    /**
     * Create an actor with a name.
     */
    explicit Actor(std::string name);

    /**
     * Destructor.
     */
    ~Actor() override;
};


#endif //PRIMAVERA_CONCURRENTE_ACTOR_H
