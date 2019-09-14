#include <unordered_map>
#include "FlowerProtocol.h"
#include "../../utils/csv/CsvLine.h"

#define FLOWERS_SEPARATOR '|'
#define TRANSACTION_SEPARATOR '#'

/**
 * Protocol:
 * producer_name,flower_type,count|producer_name,flower_type,count|...
 */

FlowerProtocol::FlowerProtocol() = default;

FlowerProtocol::~FlowerProtocol() = default;

std::string FlowerProtocol::sendFlowers(const FlowerList& flowers) const {
    std::unordered_map<Flower, size_t> groupedFlowers;
    for (const Flower& flower : flowers) {
        groupedFlowers[flower]++;
    }

    std::string data;
    for (auto& it: groupedFlowers) {
        CsvLine csv;
        csv.setNext(it.first.getProducer());
        csv.setNext(it.first.getType().getName());
        csv.setNext(it.second);
        data += csv.getCsv() + FLOWERS_SEPARATOR;
    }

    return std::move(data);
}

FlowerList FlowerProtocol::receiveFlowers(const std::string& data) const {
    FlowerList list;
    std::stringstream stream(data);
    while (true) {
        std::string line;
        std::getline(stream, line, FLOWERS_SEPARATOR);
        if (line.empty()) {
            break;
        }

        CsvLine csv(line);
        std::string producer(csv.getNext());
        FlowerType type(csv.getNext());
        int count = csv.getNextNumber();
        for (int i = 0; i < count; i++) {
            Flower flower(producer, type);
            list.push_back(flower);
        }
    }

    return list;
}

std::string FlowerProtocol::sendFlowerTransaction(const FlowerTransaction &transaction) const {
    CsvLine line;
    line.setNext(transaction.getSender());
    line.setNext(transaction.getReceiver());

    return line.getCsv() + TRANSACTION_SEPARATOR + sendFlowers(transaction.getFlowers()) + TRANSACTION_SEPARATOR;
}

FlowerTransaction FlowerProtocol::receiveFlowersTransaction(const std::string &data) const {
    std::stringstream stream(data);

    std::string line;
    std::getline(stream, line, TRANSACTION_SEPARATOR);

    CsvLine info(line);
    std::string sender = info.getNext();
    std::string receiver = info.getNext();
    std::getline(stream, line, TRANSACTION_SEPARATOR);

    FlowerTransaction transaction(sender, receiver, receiveFlowers(line));
    return transaction;
}

char FlowerProtocol::getFlowersSeparator() const {
    return FLOWERS_SEPARATOR;
}


