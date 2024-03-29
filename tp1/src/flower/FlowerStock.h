

#ifndef PRIMAVERA_CONCURRENTE_FLOWERSTOCK_H
#define PRIMAVERA_CONCURRENTE_FLOWERSTOCK_H


#include <list>
#include <unordered_map>
#include "FlowerType.h"
#include "Flower.h"
#include "../orders/Order.h"

class FlowerStock {
private:
    std::unordered_map<FlowerType, FlowerList> flowers;

public:
    /**
     * Constructor.
     */
    FlowerStock();

    /**
     * Destructor.
     */
    ~FlowerStock();

    /**
     * Add one flower to the stock.
     */
    void addFlower(Flower &&newFlower);

    /**
     * Add flowers to the stock.
     */
    void addFlowers(const FlowerList &newFlowers);

    /**
     * Get all flowers in stock.
     */
    FlowerList getAllFlowers();

    /**
     * Get all flowers of a type in stock.
     */
    FlowerList getFlowers(const FlowerType &type, int count);

    /**
     * Get all flowers needed to complete an order.
     */
    FlowerList getFlowers(const Order &order);

    /**
     * If has all flowers needed to complete an order.
     */
    bool canCompleteOrder(const Order &order);

    /**
     * Count all flowers of a type in stock.
     */
    size_t countFlowers(const FlowerType &type);

    /**
     * Count all flowers in stock.
     */
    size_t countFlowers();
};


#endif //PRIMAVERA_CONCURRENTE_FLOWERSTOCK_H
