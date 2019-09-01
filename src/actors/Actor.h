

#ifndef PRIMAVERA_CONCURRENTE_ACTOR_H
#define PRIMAVERA_CONCURRENTE_ACTOR_H


#include <string>

class Actor {
protected:
    std::string name;

public:
    Actor(std::string&& name);

    virtual ~Actor();
};


#endif //PRIMAVERA_CONCURRENTE_ACTOR_H
