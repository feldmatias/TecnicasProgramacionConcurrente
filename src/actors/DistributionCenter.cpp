

#include "DistributionCenter.h"

DistributionCenter::DistributionCenter(std::string &&name) :
    Actor(std::move(name)) {
}

DistributionCenter::~DistributionCenter() = default;
