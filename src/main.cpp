#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include "process_creators/ActorsCreator.h"
#include "comunication/comunicators/ExitComunicator.h"
#include "process_creators/LoggerCreator.h"
#include "process_creators/GeneratorsCreator.h"
#include "concurrency/Fifo.h"
#include "comunication/comunicators/ParentComunicator.h"
#include "process_creators/StatisticsCreator.h"

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

    ParentComunicator parentComunicator;
    parentComunicator.start();

    while (wait(NULL) > 0) {
        // Child process finished
    }

    remove(FIFO_FOLDER);
    return EXIT_OK;
}