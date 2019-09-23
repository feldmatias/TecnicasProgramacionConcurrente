

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
    /**
     * Create a flower with a producer and a type.
     */
    Flower(std::string producer, const FlowerType& type);

    /**
     * Destructor.
     */
    ~Flower();

    /**
     * Get producer's name.
     */
    std::string getProducer() const;

    /**
     * Get flower type.
     */
    FlowerType getType() const;

    /**
     * Compare to other flower.
     */
    bool operator==(const Flower &other) const;

};

/**
 * Hash a flower.
 */
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
