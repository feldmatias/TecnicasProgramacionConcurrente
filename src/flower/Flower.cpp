

#include "Flower.h"

#include <utility>

Flower::Flower(std::string producer, const FlowerType& type) :
    producer(std::move(producer)), type(type) {
}

Flower::~Flower() = default;

std::string Flower::getProducer() const {
    return producer;
}

FlowerType Flower::getType() const {
    return type;
}

bool Flower::operator==(const Flower &other) const {
    return producer == other.producer && type == other.type;
}
