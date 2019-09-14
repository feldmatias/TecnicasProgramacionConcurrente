

#ifndef PRIMAVERA_CONCURRENTE_RUNNABLE_H
#define PRIMAVERA_CONCURRENTE_RUNNABLE_H

#include <string>

class Runnable {
public:
    /**
     * Constructor.
     */
    Runnable() = default;

    /**
     * Destructor.
     */
    virtual ~Runnable() = default;

    /**
     * Receive data.
     */
    virtual void receiveData() = 0;

    /**
     * Get name.
     */
     virtual std::string name() = 0;

};

#endif //PRIMAVERA_CONCURRENTE_RUNNABLE_H
