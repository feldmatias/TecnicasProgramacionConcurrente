

#ifndef PRIMAVERA_CONCURRENTE_SIGNALHANDLER_H
#define PRIMAVERA_CONCURRENTE_SIGNALHANDLER_H


#include <csignal>
#include <memory.h>
#include "SignalEventHandler.h"


class SignalHandler {

private:
    static SignalEventHandler *signalHandlers[NSIG];

    /**
     * Private constructor.
     */
    SignalHandler();

    /**
     * Handle signal.
     * @param signum
     */
    static void handleSignal(int signum);

public:

    /**
     * Register signal event.
     */
    static void registerSignalEvent(int signum, SignalEventHandler *signalEvent);

    /**
     * Send signal to process.
     */
    static void sendSignal(pid_t pid, int signum);
};


#endif //PRIMAVERA_CONCURRENTE_SIGNALHANDLER_H
