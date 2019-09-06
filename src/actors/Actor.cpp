
#include "Actor.h"

#include <utility>

Actor::Actor(std::string name) :
    name(std::move(name)) {
}

Actor::~Actor() = default;
