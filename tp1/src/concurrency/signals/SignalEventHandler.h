

#ifndef PRIMAVERA_CONCURRENTE_SIGNALEVENTHANDLER_H
#define PRIMAVERA_CONCURRENTE_SIGNALEVENTHANDLER_H


class SignalEventHandler {
public:
    /**
     * Handle signal.
     */
    virtual void handleSignal() = 0;

    /**
     * Destructor;
     */
    virtual ~SignalEventHandler() = default;
};


#endif //PRIMAVERA_CONCURRENTE_SIGNALEVENTHANDLER_H
