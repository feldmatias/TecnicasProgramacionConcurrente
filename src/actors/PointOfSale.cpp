
#include "PointOfSale.h"
#include "../logger/Logger.h"
#include "../statistics/Statistics.h"
#include "../comunication/flowers/FlowerSender.h"
#include "../comunication/orders/OrderSender.h"
#include "../shipping/ShippingSystem.h"

#define SALE_POINT_NAME std::string("PuntoDeVenta")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

PointOfSale::PointOfSale(const std::string& name) :
    Actor(name) {
}

void PointOfSale::doWork(Data data) {
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
        if (stock.canCompleteOrder(client)) {
            sellFlowersToClient(client);
            clients.pop_front();
        }
    }
}

void PointOfSale::attendInternetOrders(){
    if (internetOrders.empty()) {
        return;
    }

    OrderList currentOrders;
    currentOrders.splice(currentOrders.end(), internetOrders);

    for (const Order& order : currentOrders) {
        if (stock.canCompleteOrder(order)){
            sellFlowersToInternet(order);
        } else {
            internetOrders.push_back(order);
        }
    }
}

void PointOfSale::sellFlowersToClient(const Order& order) {
    FlowerList flowers = stock.getFlowers(order);

    FlowerTransaction transaction(actorName, order, flowers);
    Logger::sendTransaction(transaction);
    Statistics::sendTransaction(transaction);
}

void PointOfSale::sellFlowersToInternet(const Order &order) {
    FlowerList flowers = stock.getFlowers(order);

    FlowerTransaction sell(actorName, order, flowers);
    Logger::sendTransaction(FlowerTransaction(actorName, SHIPPING_SYSTEM, flowers));
    Statistics::sendTransaction(sell);
    ShippingSystem::sendTransaction(sell);
}

PointOfSale::~PointOfSale() = default;
