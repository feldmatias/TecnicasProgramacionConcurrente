

#ifndef PRIMAVERA_CONCURRENTE_RUNNABLE_H
#define PRIMAVERA_CONCURRENTE_RUNNABLE_H

class Runnable {
public:
    virtual ~Runnable() = default;

    virtual void doWork() = 0;

    virtual void finish() = 0;
};

#endif //PRIMAVERA_CONCURRENTE_RUNNABLE_H
