#include "PointOfSale.h"
#include "../logger/Logger.h"
#include "../statistics/Statistics.h"
#include "../comunication/flowers/FlowerSender.h"
#include "../comunication/orders/OrderSender.h"

#define SALE_POINT_NAME std::string("PointOfSale")
#define INTERNET_NAME std::string("Internet-")
#define INTERNET_ORDERS_CONFIG std::string("config/internet-orders.csv")

std::string PointOfSale::getName(int name) {
    return SALE_POINT_NAME + std::to_string(name);
}

PointOfSale::PointOfSale(const std::string& name) :
    Actor(name),
    internetReceiver(INTERNET_ORDERS_CONFIG, name) {
    internetOrders = internetReceiver.receiveOrders();
}

void PointOfSale::receiveData(Data data) {
    if (data.getHeader() == FLOWERS_DATA) {
        receiveFlowers(data.getData());
    } else if (data.getHeader() == CLIENT_DATA) {
        receiveClient(data.getData());
    }

    attendNextClient();
    //attendInternetOrder();
}

void PointOfSale::receiveFlowers(const std::string& flowers) {
    FlowerList list = flowerReceiver.receiveFlowers(flowers);
    Logger::sendTransaction(FlowerTransaction(actorName, list));
    stock.addFlowers(list);
}

void PointOfSale::receiveClient(const std::string& clientData) {
    Order client = clientReceiver.receiveOrder(clientData);
    clients.push_back(client);
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
