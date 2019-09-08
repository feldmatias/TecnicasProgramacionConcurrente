

#ifndef PRIMAVERA_CONCURRENTE_RUNNABLE_H
#define PRIMAVERA_CONCURRENTE_RUNNABLE_H

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
     * Do something.
     */
    virtual void doWork() = 0;

    /**
     * Stop work.
     */
    virtual void finish() = 0;
};

#endif //PRIMAVERA_CONCURRENTE_RUNNABLE_H
