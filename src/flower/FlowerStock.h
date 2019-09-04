

#ifndef PRIMAVERA_CONCURRENTE_FLOWERSTOCK_H
#define PRIMAVERA_CONCURRENTE_FLOWERSTOCK_H


#include <list>
#include <unordered_map>
#include "FlowerType.h"
#include "Flower.h"

typedef std::list<Flower> FlowerList;

class FlowerStock {
private:
    std::unordered_map<FlowerType, FlowerList> flowers;

public:
    FlowerStock();

    ~FlowerStock();

    void addFlower(Flower&& newFlower);

    void addFlowers(const FlowerList& newFlowers);

    FlowerList getAllFlowers();

    FlowerList getFlowers(const FlowerType& type, int count);

    size_t countFlowers(const FlowerType& type);

    size_t countFlowers();
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERSTOCK_H
