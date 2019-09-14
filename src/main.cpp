#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include "process_creators/ActorsCreator.h"
#include "process_creators/LoggerCreator.h"
#include "process_creators/GeneratorsCreator.h"
#include "concurrency/Fifo.h"
#include "process_creators/StatisticsCreator.h"
#include "comunication/input_receiver/InputReceiver.h"
#include "actors/Producer.h"
#include "actors/DistributionCenter.h"

#define EXIT_OK 0

int main() {

    mkdir(FIFO_FOLDER, 0777);

    LoggerCreator loggerCreator;
    ProcessNames logger = loggerCreator.createLogger();
    if (logger.empty()) {
        return EXIT_OK;
    }

    StatisticsCreator statisticsCreator;
    ProcessNames statistics = statisticsCreator.createStatistics();
    if (statistics.empty()) {
        return EXIT_OK;
    }

    ActorsCreator actorsCreator;
    ProcessNames actors = actorsCreator.createActors();
    if (actors.empty()) {
        return EXIT_OK;
    }

    GeneratorsCreator generatorsCreator;
    ProcessNames generators = generatorsCreator.createGenerators();
    if (generators.empty()) {
        return EXIT_OK;
    }

    ProcessNames processNames;
    processNames.splice(processNames.end(), logger);
    processNames.splice(processNames.end(), statistics);
    processNames.splice(processNames.end(), actors);
    processNames.splice(processNames.end(), generators);
    InputReceiver inputReceiver(processNames);
    inputReceiver.start();

    while (wait(NULL) > 0) {
        // Child process finished
    }

    remove(FIFO_FOLDER);
    return EXIT_OK;
}