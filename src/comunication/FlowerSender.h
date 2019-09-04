

#ifndef PRIMAVERA_CONCURRENTE_FLOWERSENDER_H
#define PRIMAVERA_CONCURRENTE_FLOWERSENDER_H


#include "FlowerProtocol.h"

class FlowerSender {
private:
    FlowerProtocol protocol;

public:
    FlowerSender();

    ~FlowerSender();

    void sendFlowers(const std::string& receiver, const FlowerList& flowers) const;
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERSENDER_H
