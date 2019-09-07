
#include "ExitComunicator.h"

#define SHARED_MEMORY_KEY "ExitComunicatorSHM"

ExitComunicator::ExitComunicator() :
   sharedMemory(SHARED_MEMORY_KEY, false) {
}

ExitComunicator::~ExitComunicator() = default;

void ExitComunicator::setExit() {
    sharedMemory.write(true);
}

bool ExitComunicator::shouldExit() const {
    return sharedMemory.read();
}
