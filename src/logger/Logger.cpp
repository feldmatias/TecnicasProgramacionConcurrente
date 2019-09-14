#include <sstream>
#include "Logger.h"
#include "../flower/FlowerStock.h"
#include "../comunication/flowers/FlowerSender.h"

Logger::Logger() :
    receiver(LOG_FILE), logFile(LOG_FILE) {
}

void Logger::receiveData() {
    FlowerTransactionList transactions = receiver.receiveFlowerTransactions();
    for (const FlowerTransaction& transaction : transactions) {
        log(transaction);
    }
}

void Logger::log(const FlowerTransaction& transaction) {
    if (transaction.getFlowers().empty()) {
        return;
    }

    std::stringstream line;
    if (transaction.isSell()) {
        line << transaction.getSender() << " vendió flores a " << transaction.getReceiver();
    } else if (transaction.hasSender()) {
        line << transaction.getSender() << " envió flores a " << transaction.getReceiver();
    } else {
        line << transaction.getReceiver() << " recibió flores";
    }

    line << log(transaction.getFlowers());
    logFile.writeLine(line.str());
}

std::string Logger::log(const FlowerList &flowers) {
    std::stringstream stream;
    FlowerStock stock;
    stock.addFlowers(flowers);

    stream << "(";
    for (const FlowerType& type : FlowerType::all()) {
        stream << " " << stock.countFlowers(type) << " " << type.getName() << ",";
    }

    stream.seekp(-1, std::ios_base::end);
    stream << " )";
    return stream.str();
}

void Logger::sendTransaction(const FlowerTransaction& transaction) {
    FlowerSender sender;
    sender.sendFlowerTransaction(LOG_FILE, transaction);
}

std::string Logger::name() {
    return LOG_FILE;
}

Logger::~Logger() = default;
