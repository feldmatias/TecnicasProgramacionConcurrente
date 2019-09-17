

#include <sys/stat.h>
#include <sys/wait.h>
#include "PrimaveraConcurrente.h"
#include "concurrency/Fifo.h"
#include "actors/Actor.h"
#include "process_creators/ActorsCreator.h"
#include "process_creators/GeneratorsCreator.h"
#include "process_creators/StatisticsCreator.h"
#include "process_creators/LoggerCreator.h"
#include "comunication/input_receiver/InputReceiver.h"
#include "process_creators/ShippingSystemCreator.h"

PrimaveraConcurrente::PrimaveraConcurrente() {
    mkdir(FIFO_FOLDER, 0777);
    mkdir(STOCK_SAVE_FOLDER, 0777);
};

PrimaveraConcurrente::~PrimaveraConcurrente() {
    while (wait(NULL) > 0) {
        // Child process finished
    }

    std::remove(FIFO_FOLDER);
}

void PrimaveraConcurrente::start() {
    LoggerCreator loggerCreator;
    ProcessNames logger = loggerCreator.createLogger();
    if (logger.empty()) {
        return;
    } else {
        processNames.splice(processNames.end(), logger);
    }

    ShippingSystemCreator shippingSystemCreator;
    ProcessNames shippingSystem = shippingSystemCreator.createShippingSystem();
    if (shippingSystem.empty()) {
        return;
    } else {
        processNames.splice(processNames.end(), shippingSystem);
    }

    StatisticsCreator statisticsCreator;
    ProcessNames statistics = statisticsCreator.createStatistics();
    if (statistics.empty()) {
        return;
    } else {
        processNames.splice(processNames.end(), statistics);
    }

    ActorsCreator actorsCreator;
    ProcessNames actors = actorsCreator.createActors();
    if (actors.empty()) {
        return;
    } else {
        processNames.splice(processNames.end(), actors);
    }

    GeneratorsCreator generatorsCreator;
    ProcessNames generators = generatorsCreator.createGenerators();
    if (generators.empty()) {
        return;
    } else {
        processNames.splice(processNames.end(), generators);
    }

    receiveUserInput();
}

void PrimaveraConcurrente::receiveUserInput() {
    InputReceiver inputReceiver(processNames);
    inputReceiver.start();
}
