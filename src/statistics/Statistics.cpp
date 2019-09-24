#include <iostream>
#include "Statistics.h"
#include "../comunication/flowers/FlowerSender.h"

typedef std::pair<const std::string, size_t> StatisticData;

StatisticData getMaxStatisticFromHash(const StatisticsMap &hash) {
    std::string maxKey;
    size_t maxValue = 0;

    for (auto &it : hash) {
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

Statistics::Statistics() = default;

void Statistics::doWork(Data data) {
    if (data.getHeader() == SHOW_STATISTICS) {
        showStatistics();
    } else {
        receiveTransaction(data.getData());
    }
}

void Statistics::receiveTransaction(const std::string &transactionData) {
    FlowerTransaction transaction = transactionReceiver.receiveFlowerTransaction(transactionData);
    for (const Flower &flower : transaction.getFlowers()) {
        salesBySeller[transaction.getSender()]++;
        salesByType[flower.getType().getName()]++;
    }
}

void Statistics::showStatistics() {
    std::cout << std::endl;

    if (salesBySeller.empty() || salesByType.empty()) {
        std::cout << "No hubo ventas." << std::endl;
        std::cout << std::endl;
        return;
    }

    StatisticData maxSeller = getMaxStatisticFromHash(salesBySeller);
    StatisticData maxType = getMaxStatisticFromHash(salesByType);

    std::cout << "El punto de venta con más ventas es " << maxSeller.first << " con " << maxSeller.second
              << " flores vendidas." << std::endl;
    std::cout << "La flor más comprada es " << maxType.first << " con " << maxType.second << " compras." << std::endl;
    std::cout << std::endl;
}

std::string Statistics::name() {
    return STATISTICS;
}

Statistics::~Statistics() = default;
