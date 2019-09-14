
#include <unistd.h>
#include "GeneratorsCreator.h"
#include "../orders/ClientGenerator.h"
#include "../concurrency/Process.h"
#include "../../config/ConfigFiles.h"

GeneratorsCreator::GeneratorsCreator() = default;

GeneratorsCreator::~GeneratorsCreator() = default;

ProcessNames GeneratorsCreator::createGenerators() const {
    if (createClientGenerator()) {
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(CLIENTS_GENERATOR);
    return processNames;
}

bool GeneratorsCreator::createClientGenerator() const {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process, clients
        ClientGenerator generator;
        Process process(generator);
        process.run();
        return true;
    }
    return false;
}
