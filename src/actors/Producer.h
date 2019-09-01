

#ifndef PRIMAVERA_CONCURRENTE_PRODUCER_H
#define PRIMAVERA_CONCURRENTE_PRODUCER_H


#include <string>
#include "Actor.h"

class Producer : public Actor {

public:
    Producer(std::string&& name);

    ~Producer() override;
};


#endif //PRIMAVERA_CONCURRENTE_PRODUCER_H
