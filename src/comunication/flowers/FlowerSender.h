

#ifndef PRIMAVERA_CONCURRENTE_FLOWERSENDER_H
#define PRIMAVERA_CONCURRENTE_FLOWERSENDER_H


#include "FlowerProtocol.h"
#include "../DataSender.h"

class FlowerSender : public DataSender {
private:
    FlowerProtocol protocol;

public:
    FlowerSender();

    ~FlowerSender();

    void sendFlowers(const std::string& receiver, const FlowerList& flowers) const;

    void sendFlowerTransaction(const std::string& receiver, const FlowerTransaction& transaction) const;
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERSENDER_H
