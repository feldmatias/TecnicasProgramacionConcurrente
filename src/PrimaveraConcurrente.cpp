

#include <sys/stat.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>
#include "PrimaveraConcurrente.h"
#include "concurrency/fifos/Fifo.h"
#include "actors/Actor.h"
#include "process_creators/ActorsCreator.h"
#include "process_creators/GeneratorsCreator.h"
#include "process_creators/StatisticsCreator.h"
#include "process_creators/LoggerCreator.h"
#include "comunication/input_receiver/InputReceiver.h"
#include "process_creators/ShippingSystemCreator.h"
#include "concurrency/signals/SignalHandler.h"

PrimaveraConcurrente::PrimaveraConcurrente() {
    mkdir(FIFO_FOLDER, 0777);
    mkdir(STOCK_SAVE_FOLDER, 0777);
};

PrimaveraConcurrente::~PrimaveraConcurrente() {
    for (const ProcessInfo& childProcess : process) {
        waitpid(childProcess.getPid(), nullptr, 0);
    }

    SignalHandler::destroy();
    std::remove(FIFO_FOLDER);
}

void PrimaveraConcurrente::start() {
    LoggerCreator loggerCreator;
    ProcessInfoList logger = loggerCreator.createLogger();
    if (logger.empty()) {
        return;
    } else {
        process.splice(process.end(), logger);
    }

    ShippingSystemCreator shippingSystemCreator;
    ProcessInfoList shippingSystem = shippingSystemCreator.createShippingSystem();
    if (shippingSystem.empty()) {
        return;
    } else {
        process.splice(process.end(), shippingSystem);
    }

    StatisticsCreator statisticsCreator;
    ProcessInfoList statistics = statisticsCreator.createStatistics();
    if (statistics.empty()) {
        return;
    } else {
        process.splice(process.end(), statistics);
    }

    ActorsCreator actorsCreator;
    ProcessInfoList actors = actorsCreator.createActors();
    if (actors.empty()) {
        return;
    } else {
        process.splice(process.end(), actors);
    }

    GeneratorsCreator generatorsCreator;
    ProcessInfoList generators = generatorsCreator.createGenerators();
    if (generators.empty()) {
        return;
    } else {
        process.splice(process.end(), generators);
    }

    receiveUserInput();
}

void PrimaveraConcurrente::receiveUserInput() {
    InputReceiver inputReceiver(process);
    inputReceiver.start();
}
