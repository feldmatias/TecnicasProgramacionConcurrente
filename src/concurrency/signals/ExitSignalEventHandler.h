

#ifndef PRIMAVERA_CONCURRENTE_EXITSIGNALEVENTHANDLER_H
#define PRIMAVERA_CONCURRENTE_EXITSIGNALEVENTHANDLER_H


#include <csignal>
#include "SignalEventHandler.h"

class ExitSignalEventHandler : public SignalEventHandler {
private:
    sig_atomic_t quit;

public:
    /**
     * Get signal number;
     */
    static int signum();

    /**
     * Constructor.
     */
    ExitSignalEventHandler();

    /**
     * Destructor.
     */
    ~ExitSignalEventHandler() override;

    /**
     * Handle signal.
     */
    void handleSignal() override;

    /**
     * if needs to quit.
     */
    bool shouldQuit() const;
};


#endif //PRIMAVERA_CONCURRENTE_EXITSIGNALEVENTHANDLER_H
