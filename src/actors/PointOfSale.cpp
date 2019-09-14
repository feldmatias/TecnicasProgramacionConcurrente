#include "PointOfSale.h"
#include "../logger/Logger.h"
#include "../statistics/Statistics.h"

#define CLIENT_NAME std::string("Clients-")
#define SALE_POINT_NAME std::string("PointOfSale")
#define INTERNET_NAME std::string("Internet-")
#define INTERNET_ORDERS_CONFIG std::string("config/internet-orders.csv")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

std::string PointOfSale::getClientName(int name) {
    return CLIENT_NAME + getName(name);
}

PointOfSale::PointOfSale(const std::string& name) :
    Actor(name), flowerReceiver(name), clientReceiver(CLIENT_NAME + name),
    internetReceiver(INTERNET_ORDERS_CONFIG, name){
    internetOrders = internetReceiver.receiveOrders();
}

void PointOfSale::receiveData() {
    receiveFlowers();
    receiveClients();

    attendNextClient();
    attendInternetOrder();
    // TODO: implement this
}

void PointOfSale::receiveFlowers() {
    FlowerList list = flowerReceiver.receiveFlowers();
    Logger::sendTransaction(FlowerTransaction(actorName, list));
    stock.addFlowers(list);
}

void PointOfSale::receiveClients() {
    OrderList list = clientReceiver.receiveOrders();
    clients.splice(clients.end(), list);
}

void PointOfSale::attendNextClient() {
    if (clients.empty()) {
        return;
    }

    Order client = clients.front();
    for (const FlowerType& type : FlowerType::all()) {
        if (client.getFlowersCount(type) > stock.countFlowers(type)) {
            // Not enough stock
            return;
        }
    }

    sellFlowersToClient(client, clients);
}

void PointOfSale::attendInternetOrder(){
    if (internetOrders.empty()) {
        return;
    }

    Order order = internetOrders.front();
    for (const FlowerType& type : FlowerType::all()) {
        if (order.getFlowersCount(type) > stock.countFlowers(type)) {
            // Not enough stock
            return;
        }
    }
    sellFlowersToClient(order, internetOrders);
}

void PointOfSale::sellFlowersToClient(const Order& order, OrderList& orderList) {
    FlowerList flowers;
    for (const FlowerType& type : FlowerType::all()) {
        flowers.splice(flowers.end(), stock.getFlowers(type, order.getFlowersCount(type)));
    }

    FlowerTransaction transaction(actorName, order, flowers);
    Logger::sendTransaction(transaction);
    Statistics::sendTransaction(transaction);
    orderList.pop_front();
}

PointOfSale::~PointOfSale() = default;
