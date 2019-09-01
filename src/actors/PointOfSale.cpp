

#include "PointOfSale.h"

PointOfSale::PointOfSale(std::string &&name) :
    Actor(std::move(name)) {
}

PointOfSale::~PointOfSale() = default;
