#include "SignalHandler.h"

SignalEventHandler* SignalHandler::signalHandlers[NSIG];

void SignalHandler::handleSignal(int signum) {
    signalHandlers[signum]->handleSignal();
}

void SignalHandler::registerSignalEvent(int signum, SignalEventHandler* signalEvent) {
    signalHandlers[signum] = signalEvent;

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SignalHandler::handleSignal;
    sigemptyset(&sa.sa_mask);	// init blocked signals mask

    sigaction(signum, &sa, nullptr);
}

SignalHandler::SignalHandler() = default;
