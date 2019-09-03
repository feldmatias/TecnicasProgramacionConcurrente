
#include <iostream>
#include "ExitComunicator.h"

#define SHARED_MEMORY_KEY "ExitComunicatorSHM"
#define EXIT_CHAR 'q'

ExitComunicator::ExitComunicator() :
   sharedMemory(SHARED_MEMORY_KEY, false) {
}

ExitComunicator::~ExitComunicator() = default;

void ExitComunicator::start() {
    std::cout << "Ingrese " << EXIT_CHAR << " para terminar." << std::endl;
    while (std::cin.get() != EXIT_CHAR) {
        // do nothing
    }
    sharedMemory.write(true);
}

bool ExitComunicator::isExit() const {
    return sharedMemory.read();
}
