

#ifndef PRIMAVERA_CONCURRENTE_FLOWERTRANSACTION_H
#define PRIMAVERA_CONCURRENTE_FLOWERTRANSACTION_H


#include <string>
#include "Flower.h"

class FlowerTransaction {
private:
    std::string sender;
    std::string receiver;
    FlowerList flowers;

public:
    FlowerTransaction(std::string sender, std::string receiver, FlowerList flowers);

    FlowerTransaction(std::string receiver, FlowerList flowers);

    ~FlowerTransaction();

    std::string getSender() const;

    std::string getReceiver() const;

    FlowerList getFlowers() const;

    bool hasSender() const;
};

typedef std::list<FlowerTransaction> FlowerTransactionList;

#endif //PRIMAVERA_CONCURRENTE_FLOWERTRANSACTION_H
