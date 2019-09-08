#include "PointOfSale.h"
#include "../logger/Logger.h"

#define SALE_POINT_NAME std::string("PointOfSale")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

PointOfSale::PointOfSale(const std::string& name) :
    Actor(name), flowerReceiver(name) {
}

void PointOfSale::doWork() {
    receiveFlowers();
    // TODO: implement this
}

void PointOfSale::finish() {
    // TODO: implement this
}

void PointOfSale::receiveFlowers() {
    FlowerList list = flowerReceiver.receiveFlowers();
    Logger::sendTransaction(FlowerTransaction(name, list));
    stock.addFlowers(list);
}

PointOfSale::~PointOfSale() = default;
