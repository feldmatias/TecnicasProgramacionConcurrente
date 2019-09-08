#include <sys/wait.h>
#include <unistd.h>
#include "src/process_creators/ActorsCreator.h"
#include "src/comunication/ExitComunicator.h"
#include "src/process_creators/LoggerCreator.h"

#define EXIT_OK 0

int main() {

    LoggerCreator loggerCreator;
    if (loggerCreator.createLogger()) {
        return EXIT_OK;
    }

    ActorsCreator actorsCreator;
    if (actorsCreator.createActors()) {
        return EXIT_OK;
    }

    ExitComunicator exitComunicator;
    exitComunicator.start();

    while (wait(NULL) > 0) {
        // Child process finished
    }

    return EXIT_OK;
}