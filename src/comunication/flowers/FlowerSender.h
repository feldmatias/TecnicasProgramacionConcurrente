

#ifndef PRIMAVERA_CONCURRENTE_FLOWERSENDER_H
#define PRIMAVERA_CONCURRENTE_FLOWERSENDER_H


#include "FlowerProtocol.h"
#include "../DataSender.h"

#define FLOWERS_DATA "flowers"
#define TRANSACTION_DATA "transaction"

class FlowerSender {
private:
    FlowerProtocol protocol;

public:
    /**
     * Constructor.
     */
    FlowerSender();

    /**
     * Destructor.
     */
    ~FlowerSender();

    /**
     * Send flowers to a receiver.
     */
    void sendFlowers(const std::string &receiver, const FlowerList &flowers) const;

    /**
     * Send a transaction to a receiver.
     */
    void sendFlowerTransaction(const std::string &receiver, const FlowerTransaction &transaction) const;
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERSENDER_H
