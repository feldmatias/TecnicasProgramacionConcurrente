
#include "Actor.h"

Actor::Actor(const ActorInfo& info) :
    name(info.getName()) {
}

Actor::~Actor() = default;
