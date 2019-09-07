#include <sstream>
#include "OrderProtocol.h"
#include "../../utils/csv/CsvLine.h"

#define ORDER_SEPARATOR '|'

OrderProtocol::OrderProtocol() = default;

OrderProtocol::~OrderProtocol() = default;

std::string OrderProtocol::sendOrder(const Order& order) const {
    std::stringstream data;
    data << order.getClient() << ORDER_SEPARATOR;

    for (const FlowerType& type : FlowerType::all()) {
        CsvLine line;
        line.setNext(type.getName());
        line.setNext(order.getFlowersCount(type));
        data << line.getCsv() << ORDER_SEPARATOR;
    }

    return data.str();
}

Order OrderProtocol::receiveOrder(const std::string& info) const {
    std::stringstream data(info);

    std::string client;
    std::getline(data, client, ORDER_SEPARATOR);
    Order order(client);

    while (true) {
        std::string line;
        std::getline(data, line, ORDER_SEPARATOR);

        if (line.empty()) {
            break;
        }

        CsvLine csv(line);
        FlowerType type(csv.getNext());
        order.addFlowers(type, csv.getNextNumber());
    }

    return order;
}
