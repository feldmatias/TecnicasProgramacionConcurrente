

#include "ActorInfo.h"

ActorInfo::ActorInfo(std::string &&name) :
    name(std::move(name)) {
}

ActorInfo::~ActorInfo() = default;

std::string ActorInfo::getName() const {
    return name;
}
