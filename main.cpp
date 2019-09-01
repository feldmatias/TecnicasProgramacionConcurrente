#include <iostream>
#include "src/utils/file/File.h"
#include "src/utils/csv/CsvLine.h"
#include "src/flower/FlowerType.h"
#include "src/flower/Flower.h"
#include "src/config/ActorsCreator.h"

int main() {
    std::cout << "Tulip  - " << FlowerType::Tulip() << std::endl;
    std::cout << "Rose  - " << FlowerType::Rose() << std::endl << std::endl;

    Flower flower("producer", FlowerType::Tulip());
    std::cout << "Flower  - " << flower.getProducer() << "  " << flower.getType() << std::endl << std::endl;


    {
        CsvLine line;
        line.setNext(std::string("hola"));
        line.setNext("como");
        line.setNext("te");
        line.setNext("va");
        line.setNext(5);

        File file("test");
        file.writeLine(line.getCsv());
        file.writeLine(line.getCsv());
    }

    {
        File file("test");
        std::cout << file.getLine() << std::endl << std::endl;

        CsvLine output(file.getLine());
        std::cout << "Element 1  - " << output.getNext() << std::endl;
        std::cout << "Element 2  - " << output.getNext() << std::endl;
        std::cout << "Element 3  - " << output.getNext() << std::endl;
        std::cout << "Element 4  - " << output.getNext() << std::endl;
        std::cout << "Element 5  - " << output.getNextNumber() + 1 << std::endl;
        std::cout << "Element 6  - " << output.getNext() << std::endl;
    }

    remove("test");

    ActorsCreator actorsCreator;
    std::cout << "Producers  - " << actorsCreator.getProducers().size() << std::endl;
    std::cout << "Distribution Centers  - " << actorsCreator.getDistributionCenters().size() << std::endl;
    std::cout << "Points of sale  - " << actorsCreator.getPointsOfSale().size() << std::endl;

    return 0;
}