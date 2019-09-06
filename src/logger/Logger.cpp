#include <sstream>
#include "Logger.h"
#include "../flower/FlowerStock.h"

Logger::Logger() :
    receiver(LOG_FILE), logFile(LOG_FILE) {
}

void Logger::doWork() {
    FlowerTransactionList transactions = receiver.receiveFlowerTransactions();
    for (const FlowerTransaction& transaction : transactions) {
        log(transaction);
    }
}

void Logger::finish() {
    // Do nothing
}

void Logger::log(const FlowerTransaction& transaction) {
    std::stringstream line;
    if (transaction.hasSender()) {
        line << transaction.getSender() << " sent flowers to " << transaction.getReceiver();
    } else {
        line << transaction.getReceiver() << " received flowers";
    }
    logFile.writeLine(line.str());

    log(transaction.getFlowers());
}

void Logger::log(const FlowerList &flowers) {
    FlowerStock stock;
    stock.addFlowers(flowers);

    for (const FlowerType& type : FlowerType::all()) {
        std::stringstream line;
        line << "\t\t\t " << stock.countFlowers(type) << " " << type.getName();
        logFile.writeLine(line.str());
    }

    logFile.writeLine("");
}

Logger::~Logger() = default;
