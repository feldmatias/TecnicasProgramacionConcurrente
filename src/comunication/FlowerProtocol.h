

#ifndef PRIMAVERA_CONCURRENTE_FLOWERPROTOCOL_H
#define PRIMAVERA_CONCURRENTE_FLOWERPROTOCOL_H


#include "../flower/Flower.h"

class FlowerProtocol {
public:
    FlowerProtocol();

    ~FlowerProtocol();

    std::string sendFlowers(const FlowerList& flowers) const;

    FlowerList receiveFlowers(const std::string& data) const;
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERPROTOCOL_H
