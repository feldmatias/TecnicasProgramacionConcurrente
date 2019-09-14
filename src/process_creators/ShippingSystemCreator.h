

#ifndef PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEMCREATOR_H
#define PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEMCREATOR_H


#include "../concurrency/Process.h"

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
     * Returns empty if was created (child process), Process name otherwise.
     */
    ProcessNames createShippingSystem() const;
};


#endif //PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEMCREATOR_H
