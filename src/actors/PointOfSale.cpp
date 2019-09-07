#include "PointOfSale.h"
#include "../logger/Logger.h"

#define CLIENT_NAME std::string("Clients-")
#define SALE_POINT_NAME std::string("PointOfSale")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

std::string PointOfSale::getClientName(int name) {
    return CLIENT_NAME + getName(name);
}

PointOfSale::PointOfSale(const std::string& name) :
    Actor(name), flowerReceiver(name), clientReceiver(CLIENT_NAME + name) {
}

void PointOfSale::doWork() {
    receiveFlowers();
    receiveClients();
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

void PointOfSale::receiveClients() {
    OrderList list = clientReceiver.receiveOrders();
    clients.splice(clients.end(), list);
}

PointOfSale::~PointOfSale() = default;
