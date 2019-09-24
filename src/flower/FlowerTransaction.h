

#ifndef PRIMAVERA_CONCURRENTE_FLOWERTRANSACTION_H
#define PRIMAVERA_CONCURRENTE_FLOWERTRANSACTION_H


#include <string>
#include "Flower.h"
#include "../orders/Order.h"

class FlowerTransaction {
private:
    std::string sender;
    std::string receiver;
    FlowerList flowers;

public:
    /**
     * Create a transaction with a sender, a receiver and flowers.
     */
    FlowerTransaction(std::string sender, std::string receiver, FlowerList flowers);

    /**
     * Create a transaction with a receiver and flowers.
     */
    FlowerTransaction(std::string receiver, FlowerList flowers);

    /**
     * Create a transaction with a seller, a client and flowers.
     */
    FlowerTransaction(std::string seller, const Order &client, FlowerList flowers);

    /**
     * Destructor.
     */
    ~FlowerTransaction();

    /**
     * Get sender name.
     */
    std::string getSender() const;

    /**
     * Get receiver name.
     */
    std::string getReceiver() const;

    /**
     * Get flowers.
     */
    FlowerList getFlowers() const;

    /**
     * If the transaction has a sender.
     */
    bool hasSender() const;

    /**
     * If the transaction is a sell.
     */
    bool isSell() const;
};

typedef std::list<FlowerTransaction> FlowerTransactionList;

#endif //PRIMAVERA_CONCURRENTE_FLOWERTRANSACTION_H
