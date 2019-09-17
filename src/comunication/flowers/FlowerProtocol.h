

#ifndef PRIMAVERA_CONCURRENTE_FLOWERPROTOCOL_H
#define PRIMAVERA_CONCURRENTE_FLOWERPROTOCOL_H


#include "../../flower/Flower.h"
#include "../../flower/FlowerTransaction.h"

class FlowerProtocol {
public:
    /**
     * Constructor.
     */
    FlowerProtocol();

    /**
     * Destructor.
     */
    ~FlowerProtocol();

    /**
     * Convert flowers to a string.
     */
    std::string sendFlowers(const FlowerList& flowers) const;

    /**
     * Convert string to flowers.
     */
    FlowerList receiveFlowers(const std::string& data) const;

    /**
     * Convert a transaction to a string.
     */
    std::string sendFlowerTransaction(const FlowerTransaction& transaction) const;

    /**
     * Convert string to transaction.
     */
    FlowerTransaction receiveFlowersTransaction(const std::string &data) const;

    /**
     * Get flowers separator used in protocol.
     */
     char getFlowersSeparator() const;
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERPROTOCOL_H
