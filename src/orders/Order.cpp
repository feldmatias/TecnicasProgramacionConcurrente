

#include "Order.h"

#include <utility>

Order::Order(std::string client) :
    client(std::move(client)) {
}

void Order::addFlowers(const FlowerType& type, size_t count) {
    orders[type] += count;
}

std::string Order::getClient() const {
    return client;
}

size_t Order::getFlowersCount(const FlowerType& type) const {
    if (orders.find(type) != orders.end()) {
        return orders.at(type);
    }
    return 0;
}

Order::~Order() = default;
