

#include "InternetGenerator.h"
#include "../utils/common/Random.h"
#include "../../config/ConfigFiles.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../utils/csv/CsvLine.h"

InternetGenerator::InternetGenerator() {
    lastOrder = 0;
    initializeOrders();
}

void InternetGenerator::receiveData(Data data) {
    if (Random::probability(config.clientGeneratorRate())) {
        sendOrder();
    }
}

std::string InternetGenerator::name() {
    return INTERNET_GENERATOR;
}

void InternetGenerator::initializeOrders() {
    ReadOnlyFile file(INTERNET_ORDERS_CONFIG);
    while (file.hasMoreData()) {
        std::string data = file.getLine();
        if (data.empty()) {
            continue;
        }

        CsvLine line(data);
        Order order;
        while(true) {
            std::string typeName = line.getNext();
            if (typeName.empty()) {
                break;
            }

            FlowerType type(typeName);
            order.addFlowers(type, line.getNextNumber());
        }
        orders.push_back(order);
    }
}

void InternetGenerator::sendOrder() {
    lastOrder++;
}

InternetGenerator::~InternetGenerator() = default;
