

#ifndef PRIMAVERA_CONCURRENTE_ACTOR_H
#define PRIMAVERA_CONCURRENTE_ACTOR_H

#include <string>
#include "../concurrency/process/Runnable.h"
#include "../config/ActorsConfig.h"
#include "../flower/FlowerStock.h"
#include "../comunication/flowers/FlowerProtocol.h"

#define STOCK_SAVE_FOLDER "stock"

class Actor : public Runnable {
private:
    FlowerProtocol protocol;

    /**
    * Save stock of flowers.
    */
    void saveStock();

    /**
     * Restore stock of flowers.
     */
    void restoreStock();

    /**
     * Get stock file name.
     */
     std::string stockFileName() const;

protected:
    std::string actorName;
    FlowerStock stock;
    ActorsConfig config;

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
