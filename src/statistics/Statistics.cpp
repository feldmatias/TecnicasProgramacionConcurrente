#include <iostream>
#include "Statistics.h"
#include "../comunication/flowers/FlowerSender.h"

#define STATISTICS "statistics"

typedef std::pair<const std::string, size_t> StatisticData;

StatisticData getMaxFromHash(const StatisticsMap& hash) {
    std::string maxKey;
    size_t maxValue = 0;

    for (auto & it : hash) {
        if (it.second >= maxValue) {
            maxKey = it.first;
            maxValue = it.second;
        }
    }

    return StatisticData(maxKey, maxValue);
}

void Statistics::sendTransaction(const FlowerTransaction &transaction) {
    FlowerSender sender;
    sender.sendFlowerTransaction(STATISTICS, transaction);
}

Statistics::Statistics() :
    transactionReceiver(STATISTICS) {
}

void Statistics::doWork() {
    receiveTransactions();
    if (comunicator.shouldShowStatistics()) {
        showStatistics();
    }
}

void Statistics::finish() {
 // Do nothing
}

void Statistics::receiveTransactions() {
    FlowerTransactionList transactions = transactionReceiver.receiveFlowerTransactions();
    for (const FlowerTransaction& transaction : transactions) {
        for (const Flower& flower : transaction.getFlowers()) {
            salesBySeller[transaction.getSender()]++;
            salesByType[flower.getType().getName()]++;
        }
    }
}

void Statistics::showStatistics() {
    if (salesBySeller.empty() || salesByType.empty()) {
        std::cout << "No hubo ventas." << std::endl;
        return;
    }

    StatisticData maxSeller = getMaxFromHash(salesBySeller);
    StatisticData maxType = getMaxFromHash(salesByType);

    std::cout << "El punto de venta con mas ventas es " << maxSeller.first << " con " << maxSeller.second << " flores vendidas." << std::endl;
    std::cout << "La flor mas comprada es " << maxType.first << " con " << maxType.second << " compras." << std::endl;
}

Statistics::~Statistics() = default;
