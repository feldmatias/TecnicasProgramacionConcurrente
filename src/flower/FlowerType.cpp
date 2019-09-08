#include "FlowerType.h"

#include <utility>

const char* TULIP = "Tulip";
const char* ROSE = "Rose";

FlowerType FlowerType::Tulip() {
    return FlowerType(TULIP);
}

FlowerType FlowerType::Rose() {
    return FlowerType(ROSE);
}

std::vector<FlowerType> FlowerType::all() {
    return { Tulip(), Rose() };
}

FlowerType::FlowerType(std::string type) : type(std::move(type)){
}

FlowerType::~FlowerType() = default;

std::ostream &operator<<(std::ostream &os, const FlowerType &flowerType) {
    return os << flowerType.type;
}

bool FlowerType::operator==(const FlowerType &other) const {
    return type == other.type;
}

std::string FlowerType::getType() const {
    return type;
}
