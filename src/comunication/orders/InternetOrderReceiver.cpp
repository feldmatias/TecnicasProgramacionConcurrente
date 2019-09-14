
#include <string>
#include "InternetOrderReceiver.h"
#include "../../orders/Order.h"
#include "../../utils/csv/CsvLine.h"
#include "../../orders/ClientGenerator.h"

InternetOrderReceiver::InternetOrderReceiver(const std::string& receiver, std::string name)
    : ordersFile(receiver), name(std::move(name)){
    clientNumber = 0;
}

OrderList InternetOrderReceiver::receiveOrders() {
    OrderList list;
    while (true) {
        std::string line = ordersFile.getLine();
        if (line.empty()) {
            break;
        }
        CsvLine csvLine(line);
        std::string salePoint = csvLine.getNext();
        if(salePoint == name){
            list.push_back(processOrder(line));
            clientNumber++;
        }
    }

    return list;
}

Order InternetOrderReceiver::processOrder(std::string info) {
    CsvLine line(info);
    line.getNext();
    Order order(INTERNET_NAME + "-" + std::to_string(clientNumber));
    for (const FlowerType& type : FlowerType::all()) {
        order.addFlowers(type, line.getNextNumber());
    }
    return order;
}

InternetOrderReceiver::~InternetOrderReceiver() = default;
