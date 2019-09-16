
#include "Actor.h"

#include <utility>

Actor::Actor(std::string name) :
        actorName(std::move(name)) {
}

std::string Actor::name() {
    return actorName;
}

Actor::~Actor() = default;
