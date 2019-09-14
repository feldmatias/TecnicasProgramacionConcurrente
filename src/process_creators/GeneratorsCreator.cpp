
#include "GeneratorsCreator.h"
#include "../orders/ClientGenerator.h"
#include "../concurrency/Process.h"
#include "../orders/InternetGenerator.h"

GeneratorsCreator::GeneratorsCreator() = default;

GeneratorsCreator::~GeneratorsCreator() = default;

ProcessNames GeneratorsCreator::createGenerators() const {
    if (createClientGenerator()) {
        return ProcessNames();
    }

    if (createInternetGenerator()) {
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(CLIENTS_GENERATOR);
    processNames.push_back(INTERNET_GENERATOR);
    return processNames;
}

bool GeneratorsCreator::createClientGenerator() const {
    ClientGenerator generator;
    return Process::create(generator);
}

bool GeneratorsCreator::createInternetGenerator() const {
    InternetGenerator generator;
    return Process::create(generator);
}
