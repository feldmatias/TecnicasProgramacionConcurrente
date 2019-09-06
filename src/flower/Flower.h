

#ifndef PRIMAVERA_CONCURRENTE_FLOWER_H
#define PRIMAVERA_CONCURRENTE_FLOWER_H

#include <list>
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

    bool operator==(const Flower &other) const;

};

namespace std {
    template <>
    struct hash<Flower> {
        std::size_t operator()(const Flower& key) const {
            return hash<string>()(key.getType().getName() + key.getProducer());
        }
    };
}

typedef std::list<Flower> FlowerList;

#endif //PRIMAVERA_CONCURRENTE_FLOWER_H
