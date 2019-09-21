

#ifndef PRIMAVERA_CONCURRENTE_SIGNALEVENTHANDLER_H
#define PRIMAVERA_CONCURRENTE_SIGNALEVENTHANDLER_H


class SignalEventHandler {
public:
    /**
     * Handle signal.
     */
    virtual void handleSignal() = 0;
};


#endif //PRIMAVERA_CONCURRENTE_SIGNALEVENTHANDLER_H
