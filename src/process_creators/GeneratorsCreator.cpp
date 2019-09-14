
#include <unistd.h>
#include "GeneratorsCreator.h"
#include "../orders/ClientGenerator.h"
#include "../concurrency/Process.h"
#include "../../config/ConfigFiles.h"
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
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        ClientGenerator generator;
        Process process(generator);
        process.run();
        return true;
    }
    return false;
}

bool GeneratorsCreator::createInternetGenerator() const {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        InternetGenerator generator;
        Process process(generator);
        process.run();
        return true;
    }
    return false;
}
