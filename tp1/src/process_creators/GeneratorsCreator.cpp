
#include "GeneratorsCreator.h"
#include "../orders/ClientGenerator.h"
#include "../concurrency/process/DataSenderProcess.h"
#include "../orders/InternetGenerator.h"

GeneratorsCreator::GeneratorsCreator() = default;

GeneratorsCreator::~GeneratorsCreator() = default;

ProcessInfoList GeneratorsCreator::createGenerators() const {
    ProcessInfo clientsGenerator = createClientGenerator();
    if (clientsGenerator.isChildProcess()) {
        return ProcessInfoList();
    }

    ProcessInfo internetGenerator = createInternetGenerator();
    if (internetGenerator.isChildProcess()) {
        return ProcessInfoList();
    }

    ProcessInfoList process;
    process.push_back(clientsGenerator);
    process.push_back(internetGenerator);
    return process;
}

ProcessInfo GeneratorsCreator::createClientGenerator() const {
    ClientGenerator generator;
    return DataSenderProcess::create(generator);
}

ProcessInfo GeneratorsCreator::createInternetGenerator() const {
    InternetGenerator generator;
    return DataSenderProcess::create(generator);
}
