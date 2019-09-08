

#include "FlowerStock.h"

FlowerStock::FlowerStock() = default;

FlowerStock::~FlowerStock() = default;

void FlowerStock::addFlower(Flower&& newFlower) {
    flowers[newFlower.getType()].push_back(std::move(newFlower));
}

void FlowerStock::addFlowers(const FlowerList& newFlowers) {
    for (Flower flower : newFlowers) {
        addFlower(std::move(flower));
    }
}

FlowerList FlowerStock::getAllFlowers() {
    FlowerList list;
    for (const FlowerType& type : FlowerType::all()) {
        list.splice(list.end(), flowers[type]);
    }
    return std::move(list);
}

FlowerList FlowerStock::getFlowers(const FlowerType &type, int count) {
    FlowerList list;
    auto it = flowers[type].begin();
    std::advance(it, count);
    list.splice(list.end(), flowers[type], flowers[type].begin(), it);
    return list;
}

size_t FlowerStock::countFlowers(const FlowerType &type){
    return flowers[type].size();
}

size_t FlowerStock::countFlowers() {
    size_t count = 0;
    for (const FlowerType& type : FlowerType::all()) {
        count += flowers[type].size();
    }
    return count;
}
