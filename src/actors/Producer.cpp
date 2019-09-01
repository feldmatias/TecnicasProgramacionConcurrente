

#include "Producer.h"

Producer::Producer(std::string &&name) :
    Actor(std::move(name)) {
}

Producer::~Producer() = default;
