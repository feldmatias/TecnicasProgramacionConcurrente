

#ifndef PRIMAVERA_CONCURRENTE_RUNNABLE_H
#define PRIMAVERA_CONCURRENTE_RUNNABLE_H

#include <string>
#include "../../comunication/Data.h"

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
    virtual void receiveData(Data data) = 0;

    /**
     * Get name.
     */
     virtual std::string name() = 0;

     /**
      * If receives data from other process.
      */
      virtual bool receivesData() {
          return true;
      }

};

#endif //PRIMAVERA_CONCURRENTE_RUNNABLE_H
