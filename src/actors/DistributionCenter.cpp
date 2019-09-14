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
    Actor(name) {
    boxSize = config.centersBoxSize();
    restoreStock();
}

void DistributionCenter::receiveData(Data data) {
    receiveFlowers(data.getData());
    processFlowers();
}

void DistributionCenter::saveStock(){
    /*WriteOnlyFile saveFile(PERSISTENCE_PATH + actorName + ".csv");
    FlowerList flowers = stock.getAllFlowers();
    for(const Flower& flower : flowers){
        CsvLine line;
        line.setNext(flower.getType().getName());
        line.setNext(flower.getProducer());
        saveFile.writeLine(line.getCsv());
    }*/
}

void DistributionCenter::receiveFlowers(const std::string& flowers) {
    FlowerList list = flowerReceiver.receiveFlowers(flowers);
    Logger::sendTransaction(FlowerTransaction(actorName, list));
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
    Logger::sendTransaction(FlowerTransaction(actorName, salePoint, flowers));
}

void DistributionCenter::restoreStock() {
    /*ReadOnlyFile readFile(PERSISTENCE_PATH + actorName + ".csv");
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
    stock.addFlowers(flowerList);*/
}

DistributionCenter::~DistributionCenter() = default;
