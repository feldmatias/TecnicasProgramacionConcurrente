
#include "InternetGenerator.h"
#include "../utils/common/Random.h"
#include "../ConfigFiles.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../utils/csv/CsvLine.h"
#include "../actors/PointOfSale.h"
#include "../utils/common/TimeSimulator.h"

InternetGenerator::InternetGenerator() {
    lastOrder = 0;
    initializeOrders();
}

void InternetGenerator::doWork(Data data) {
    if (Random::probability(config.clientGeneratorRate())) {
        sendOrder();
    }
    TimeSimulator::simulate();
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
        while (true) {
            std::string typeName = line.getNext();
            if (typeName.empty()) {
                break;
            }

            FlowerType type(typeName);
            int count = line.getNextNumber();
            order.addFlowers(type, count);
        }
        orders.push_back(order);
    }
}

void InternetGenerator::sendOrder() {
    Order order = orders.front();
    order.setClient(INTERNET_NAME + std::to_string(lastOrder));

    int salePointNumber = Random::generate(actorsConfig.numberOfPointsOfSale());
    std::string salePoint = PointOfSale::getName(salePointNumber);
    orderSender.sendInternetOrder(salePoint, order);

    lastOrder++;
    orders.pop_front();
    orders.push_back(order);
}

InternetGenerator::~InternetGenerator() = default;
