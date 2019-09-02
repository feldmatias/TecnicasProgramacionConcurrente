

#include "Actor.h"

Actor::Actor(ActorInfo& info) :
    name(info.getName()) {
}

Actor::~Actor() = default;
