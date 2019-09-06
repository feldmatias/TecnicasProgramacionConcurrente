#include "PointOfSale.h"

#define SALE_POINT_NAME std::string("PointOfSale")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

PointOfSale::PointOfSale(int name) :
    Actor(getName(name)) {
}

void PointOfSale::doWork() {
    // TODO: implement this
}

void PointOfSale::finish() {
    // TODO: implement this
}

PointOfSale::~PointOfSale() = default;
