

#ifndef PRIMAVERA_CONCURRENTE_ACTOR_H
#define PRIMAVERA_CONCURRENTE_ACTOR_H

#include <string>
#include "../concurrency/Runnable.h"
#include "../config/ActorsConfig.h"
#include "../flower/FlowerStock.h"

#define STOCK_SAVE_FOLDER "stock"

class Actor : public Runnable {
protected:
    std::string actorName;
    FlowerStock stock;
    ActorsConfig config;

    /**
     * Save stock of flowers.
     */
     void saveStock();

     /**
      * Restore stock of flowers.
      */
      void restoreStock();

public:
    /**
     * Create an actor with a name.
     */
    explicit Actor(std::string name);

    /**
     * Destructor.
     */
    ~Actor() override;

    /**
     * Get name.
     */
    std::string name() override;
};


#endif //PRIMAVERA_CONCURRENTE_ACTOR_H
