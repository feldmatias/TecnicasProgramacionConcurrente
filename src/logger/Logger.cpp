#include <sstream>
#include <algorithm>
#include "Logger.h"
#include "../comunication/flowers/FlowerSender.h"
#include "../shipping/ShippingSystem.h"
#include "../flower/FlowerStock.h"

Logger::Logger() :
        logFile(LOG_FILE) {
}

std::string Logger::name() {
    return LOG_FILE;
}

void Logger::doWork(Data data) {
    FlowerTransaction transaction = receiver.receiveFlowerTransaction(data.getData());
    if (data.getHeader() == TRANSACTION_DATA) {
        log(transaction);
    } else if (data.getHeader() == DISPATCH_NOTE_DATA) {
        logDispatchNote(transaction);
    }
}

void Logger::log(const FlowerTransaction &transaction) {
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

    stream << " (";
    for (const FlowerType &type : FlowerType::all()) {
        stream << " " << stock.countFlowers(type) << " " << type.getName() << ",";
    }

    stream.seekp(-1, std::ios_base::end);
    stream << " ) ";
    return stream.str();
}

void Logger::logDispatchNote(const FlowerTransaction &transaction) {
    if (transaction.getFlowers().empty()) {
        return;
    }

    std::stringstream line;
    line << "Remito generado para " << transaction.getReceiver();

    FlowerProtocol protocol;
    std::stringstream data(protocol.sendFlowers(transaction.getFlowers()));

    while (true) {
        std::string item;
        std::getline(data, item, protocol.getFlowersSeparator());

        if (item.empty()) {
            break;
        }

        std::replace(item.begin(), item.end(), ',', ' ');
        line << '\n' << "\t\t" << item;
    }

    logFile.writeLine(line.str());
}

void Logger::sendTransaction(const FlowerTransaction &transaction) {
    FlowerProtocol protocol;
    DataSender::sendData(LOG_FILE, TRANSACTION_DATA, protocol.sendFlowerTransaction(transaction));
}

void Logger::sendDispatchNote(const FlowerTransaction &transaction) {
    FlowerProtocol protocol;
    DataSender::sendData(LOG_FILE, DISPATCH_NOTE_DATA, protocol.sendFlowerTransaction(transaction));
}

Logger::~Logger() = default;
