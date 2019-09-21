

#include "ExitSignalEventHandler.h"

int ExitSignalEventHandler::signum() {
    return SIGQUIT;
}

ExitSignalEventHandler::ExitSignalEventHandler() : quit(false) {
}

void ExitSignalEventHandler::handleSignal() {
    quit = true;
}

bool ExitSignalEventHandler::shouldQuit() const {
    return quit;
}

ExitSignalEventHandler::~ExitSignalEventHandler() = default;
