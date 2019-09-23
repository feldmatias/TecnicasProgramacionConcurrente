

#ifndef PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEMCREATOR_H
#define PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEMCREATOR_H


#include "../concurrency/process/ProcessInfo.h"

class ShippingSystemCreator {
public:
    /**
     * Constructor.
     */
    ShippingSystemCreator();

    /**
     * Destructor.
     */
    ~ShippingSystemCreator();

    /**
     * Create shipping system.
     * Returns empty if was created (child process), Process info otherwise.
     */
    ProcessInfoList createShippingSystem() const;
};


#endif //PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEMCREATOR_H
