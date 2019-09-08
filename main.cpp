#include <sys/wait.h>
#include <unistd.h>
#include "src/config/ActorsCreator.h"
#include "src/comunication/ExitComunicator.h"

#define EXIT_OK 0

int main() {
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