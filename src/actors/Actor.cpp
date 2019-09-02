
#include <unistd.h>
#include <iostream>
#include "Actor.h"

Actor::Actor(const ActorInfo& info) :
    name(info.getName()) {
    std::cout << "Actor created: " << name << " - " << getpid() << " parent: " << getppid() << std::endl; //TODO: remove this
}

Actor::~Actor() = default;
