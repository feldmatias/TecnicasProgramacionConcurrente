#include "PointOfSale.h"
#include "../logger/Logger.h"
#include "../statistics/Statistics.h"
#include "../comunication/flowers/FlowerSender.h"
#include "../comunication/orders/OrderSender.h"

#define SALE_POINT_NAME std::string("PointOfSale")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

PointOfSale::PointOfSale(const std::string& name) :
    Actor(name) {
}

void PointOfSale::receiveData(Data data) {
    if (data.getHeader() == FLOWERS_DATA) {
        receiveFlowers(data.getData());
    } else if (data.getHeader() == CLIENT_DATA) {
        receiveClient(data.getData());
    } else if (data.getHeader() == INTERNET_ORDER_DATA) {
        receiveInternetOrder(data.getData());
    }

    attendClients();
    attendInternetOrders();
}

void PointOfSale::receiveFlowers(const std::string& flowers) {
    FlowerList list = flowerReceiver.receiveFlowers(flowers);
    Logger::sendTransaction(FlowerTransaction(actorName, list));
    stock.addFlowers(list);
}

void PointOfSale::receiveClient(const std::string& clientData) {
    Order client = orderReceiver.receiveOrder(clientData);
    clients.push_back(client);
}

void PointOfSale::receiveInternetOrder(const std::string &orderData) {
    Order order = orderReceiver.receiveOrder(orderData);
    internetOrders.push_back(order);
}

void PointOfSale::attendClients() {
    while (!clients.empty()) {
        Order client = clients.front();
        for (const FlowerType& type : FlowerType::all()) {
            if (client.getFlowersCount(type) > stock.countFlowers(type)) {
                // Not enough stock
                // Do not attend next clients.
                return;
            }
        }

        sellFlowersToClient(client);
        clients.pop_front();
    }
}

void PointOfSale::attendInternetOrders(){
    if (internetOrders.empty()) {
        return;
    }

    OrderList currentOrders = internetOrders;
    internetOrders.clear();

    while (!currentOrders.empty()) {
        Order order = currentOrders.front();
        for (const FlowerType& type : FlowerType::all()) {
            if (order.getFlowersCount(type) > stock.countFlowers(type)) {
                // Not enough stock
                // Move to next order
                currentOrders.pop_front();
                internetOrders.push_back(order);
                continue;
            }
        }

        sellFlowersToInternet(order);
        currentOrders.pop_front();
    }
}

void PointOfSale::sellFlowersToClient(const Order& order) {
    FlowerList flowers;
    for (const FlowerType& type : FlowerType::all()) {
        flowers.splice(flowers.end(), stock.getFlowers(type, order.getFlowersCount(type)));
    }

    FlowerTransaction transaction(actorName, order, flowers);
    Logger::sendTransaction(transaction);
    Statistics::sendTransaction(transaction);
}

void PointOfSale::sellFlowersToInternet(const Order &order) {
    FlowerList flowers;
    for (const FlowerType& type : FlowerType::all()) {
        flowers.splice(flowers.end(), stock.getFlowers(type, order.getFlowersCount(type)));
    }

    FlowerTransaction transaction(actorName, order, flowers);
    Logger::sendTransaction(transaction);
    Statistics::sendTransaction(transaction);
    //TODO send to shipping system
}

PointOfSale::~PointOfSale() = default;
