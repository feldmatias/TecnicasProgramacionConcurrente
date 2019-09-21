

#include "ShippingSystemCreator.h"
#include "../shipping/ShippingSystem.h"

ShippingSystemCreator::ShippingSystemCreator() = default;

ShippingSystemCreator::~ShippingSystemCreator() = default;

ProcessInfoList ShippingSystemCreator::createShippingSystem() const {
    ShippingSystem system;
    ProcessInfo processInfo = DataReceiverProcess::create(system);
    if (processInfo.isChildProcess()) {
        return ProcessInfoList();
    }

    ProcessInfoList process;
    process.push_back(processInfo);
    return process;
}
