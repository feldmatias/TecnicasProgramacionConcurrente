#include "DistributionCenter.h"
#include "../utils/common/Random.h"
#include "PointOfSale.h"
#include "../logger/Logger.h"
#include "../../config/ConfigFiles.h"

#define CENTER_NAME std::string("DistributionCenter")

std::string DistributionCenter::getName(int name) {
    return CENTER_NAME + std::to_string(name);
}

DistributionCenter::DistributionCenter(const std::string& name) :
    Actor(name), flowerReceiver(name) {
    boxSize = config.centersBoxSize();
    restoreStock();
}

void DistributionCenter::doWork() {
    receiveFlowers();
    processFlowers();
}

void DistributionCenter::finish() {
    size_t oldStock = stock.countFlowers();
    size_t newStock;
    while(true){
        receiveFlowers();
        newStock = stock.countFlowers();
        if(newStock == oldStock) break;
    }
    saveStock();
}

void DistributionCenter::saveStock(){
    WriteOnlyFile saveFile(PERSISTENCE_PATH + name + ".csv");
    FlowerList flowers = stock.getAllFlowers();
    for(const Flower& flower : flowers){
        CsvLine line;
        line.setNext(flower.getType().getName());
        line.setNext(flower.getProducer());
        saveFile.writeLine(line.getCsv());
    }
}

void DistributionCenter::receiveFlowers() {
    FlowerList list = flowerReceiver.receiveFlowers();
    Logger::sendTransaction(FlowerTransaction(name, list));
    stock.addFlowers(list);
}

void DistributionCenter::processFlowers() {
    for (const FlowerType& type : FlowerType::all()) {
        if (stock.countFlowers(type) >= boxSize) {
            sendFlowers(type);
        }
    }
}

void DistributionCenter::sendFlowers(const FlowerType& type) {
    int salePointNumber = Random::generate(config.numberOfPointsOfSale());
    std::string salePoint = PointOfSale::getName(salePointNumber);

    FlowerList flowers = stock.getFlowers(type, boxSize);
    flowerSender.sendFlowers(salePoint, flowers);
    Logger::sendTransaction(FlowerTransaction(name, salePoint, flowers));
}

void DistributionCenter::restoreStock() {
    ReadOnlyFile readFile(PERSISTENCE_PATH + name + ".csv");
    FlowerList flowerList;
    while(true){
        std::string line(readFile.getLine());
        if(line.empty()) break;
        CsvLine csvLine(line);
        FlowerType type = FlowerType(csvLine.getNext());
        std::string producer(csvLine.getNext());
        Flower newFlower = Flower(producer, type);
        flowerList.push_back(std::move(newFlower));
    }
    stock.addFlowers(flowerList);
}

DistributionCenter::~DistributionCenter() = default;
