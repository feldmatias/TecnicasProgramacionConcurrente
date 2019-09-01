

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

FlowerType::FlowerType(std::string type) : type(std::move(type)){
}

FlowerType::~FlowerType() = default;

std::ostream &operator<<(std::ostream &os, const FlowerType &flowerType) {
    return os << flowerType.type;
}
