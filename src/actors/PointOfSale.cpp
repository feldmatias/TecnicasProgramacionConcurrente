#include "PointOfSale.h"

#include <utility>

#define SALE_POINT_NAME std::string("PointOfSale")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

PointOfSale::PointOfSale(std::string name) :
    Actor(std::move(name)) {
}

void PointOfSale::doWork() {
    // TODO: implement this
}

void PointOfSale::finish() {
    // TODO: implement this
}

PointOfSale::~PointOfSale() = default;
