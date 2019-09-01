

#include "Flower.h"

#include <utility>

Flower::Flower(std::string producer, FlowerType type) :
    producer(std::move(producer)), type(type) {
}

Flower::~Flower() = default;

std::string Flower::getProducer() const {
    return producer;
}

FlowerType Flower::getType() const {
    return type;
}
