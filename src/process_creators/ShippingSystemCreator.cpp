

#include "ShippingSystemCreator.h"
#include "../shipping/ShippingSystem.h"

ShippingSystemCreator::ShippingSystemCreator() = default;

ShippingSystemCreator::~ShippingSystemCreator() = default;

ProcessNames ShippingSystemCreator::createShippingSystem() const {
    ShippingSystem system;
    if (Process::create(system)) {
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(system.name());
    return processNames;
}
