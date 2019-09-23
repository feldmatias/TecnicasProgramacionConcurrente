
#include "Actor.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../logger/Logger.h"

#include <utility>

Actor::Actor(std::string name) :
        actorName(std::move(name)) {
    restoreStock();
}

std::string Actor::name() {
    return actorName;
}

void Actor::saveStock() {
    std::string data = protocol.sendFlowers(stock.getAllFlowers());
    WriteOnlyFile saveFile(stockFileName());
    saveFile.writeLine(data);
}

void Actor::restoreStock() {
    ReadOnlyFile readFile(stockFileName());
    if (!readFile.hasMoreData()) {
        return;
    }

    std::string data = readFile.getLine();
    if (!data.empty()) {
        FlowerList flowers = protocol.receiveFlowers(data);
        stock.addFlowers(flowers);
        Logger::sendTransaction(FlowerTransaction(actorName + "(Stock Inicial)", flowers));
    }
}

std::string Actor::stockFileName() const {
    return std::string(STOCK_SAVE_FOLDER) + '/' + actorName;
}

Actor::~Actor() {
    saveStock();
}
