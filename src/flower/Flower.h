

#ifndef PRIMAVERA_CONCURRENTE_FLOWER_H
#define PRIMAVERA_CONCURRENTE_FLOWER_H


#include <string>
#include "FlowerType.h"

class Flower {
private:
    std::string producer;
    FlowerType type;

public:
    Flower(std::string producer, FlowerType type);

    ~Flower();

    std::string getProducer() const;

    FlowerType getType() const;

};


#endif //PRIMAVERA_CONCURRENTE_FLOWER_H
