#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include "src/config/ActorsCreator.h"

#define EXIT_OK 0

int main() {
    ActorsCreator actorsCreator;
    if (actorsCreator.createActors()) {
        return EXIT_OK;
    }

    while (pid_t pid = wait(NULL) > 0) {
        std::cout << "Process finished: " << pid << std::endl;
    }

    std::cout << "Parent finished: " << getpid() << std::endl;
    return EXIT_OK;
}