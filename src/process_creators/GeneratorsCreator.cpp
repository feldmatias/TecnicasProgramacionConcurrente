
#include <unistd.h>
#include "GeneratorsCreator.h"
#include "../orders/ClientGenerator.h"
#include "../concurrency/Process.h"
#include "../../config/ConfigFiles.h"

GeneratorsCreator::GeneratorsCreator() = default;

GeneratorsCreator::~GeneratorsCreator() = default;

bool GeneratorsCreator::createGenerators() const {
    if (createClientGenerator()) {
        return true;
    }

    return false;
}

bool GeneratorsCreator::createClientGenerator() const {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process, clients
        ClientGenerator generator(CLIENTS_CONFIG);
        Process process(generator);
        process.run();
        return true;
    }
    return false;
}
