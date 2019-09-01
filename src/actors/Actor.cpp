

#include "Actor.h"

Actor::Actor(std::string &&name) :
    name(std::move(name)) {
}

Actor::~Actor() = default;
