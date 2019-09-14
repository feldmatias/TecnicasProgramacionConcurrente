
#include "Actor.h"

#include <utility>

Actor::Actor(std::string name) :
        actorName(std::move(name)) {
}

std::string Actor::name() {
    return actorName;
}

void Actor::saveStock() {
/*WriteOnlyFile saveFile(PERSISTENCE_PATH + actorName + ".csv");
    FlowerList flowers = stock.getAllFlowers();
    for(const Flower& flower : flowers){
        CsvLine line;
        line.setNext(flower.getType().getName());
        line.setNext(flower.getProducer());
        saveFile.writeLine(line.getCsv());
    }*/
}

void Actor::restoreStock() {
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

Actor::~Actor() = default;
