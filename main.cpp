#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include "src/process_creators/ActorsCreator.h"
#include "src/comunication/comunicators/ExitComunicator.h"
#include "src/process_creators/LoggerCreator.h"
#include "src/process_creators/GeneratorsCreator.h"
#include "src/concurrency/Fifo.h"
#include "src/comunication/comunicators/ParentComunicator.h"

#define EXIT_OK 0

int main() {

    mkdir(FIFO_FOLDER, 0777);

    LoggerCreator loggerCreator;
    if (loggerCreator.createLogger()) {
        return EXIT_OK;
    }

    ActorsCreator actorsCreator;
    if (actorsCreator.createActors()) {
        return EXIT_OK;
    }

    GeneratorsCreator generatorsCreator;
    if (generatorsCreator.createGenerators()) {
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