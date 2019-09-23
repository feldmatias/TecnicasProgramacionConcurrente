#include "FlowerType.h"

#include <utility>

#define TULIP "Tulipan"
#define ROSE "Rosa"


std::vector<FlowerType> FlowerType::all() {
    return { FlowerType(TULIP), FlowerType(ROSE) };
}

FlowerType::FlowerType(std::string type) : type(std::move(type)){
}

FlowerType::~FlowerType() = default;

bool FlowerType::operator==(const FlowerType &other) const {
    return type == other.type;
}

std::string FlowerType::getName() const {
    return type;
}
