

#ifndef PRIMAVERA_CONCURRENTE_SIGNALHANDLER_H
#define PRIMAVERA_CONCURRENTE_SIGNALHANDLER_H


#include <csignal>
#include <memory.h>
#include <unordered_map>
#include "SignalEventHandler.h"


class SignalHandler {

private:
    static SignalHandler* instance;
    static std::unordered_map<int, SignalEventHandler&> signalEvents;

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
     * Singleton.
     */
    static SignalHandler& getInstance();

    /**
     * Destroy signal handler.
     */
    static void destroy();

    /**
     * Register signal event.
     */
    void registerSignalEvent(int signum, SignalEventHandler& signalEvent);
};


#endif //PRIMAVERA_CONCURRENTE_SIGNALHANDLER_H
