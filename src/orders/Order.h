#ifndef PRIMAVERA_CONCURRENTE_ORDER_H
#define PRIMAVERA_CONCURRENTE_ORDER_H

#include <list>
#include <string>
#include <unordered_map>
#include "../flower/FlowerType.h"

class Order {
private:
    std::string client;
    std::unordered_map<FlowerType, size_t> orders;

public:
    /**
     * Create an order.
     */
    explicit Order(std::string client);

    /**
     * Create an order.
     */
    Order();

    /**
     * Destructor.
     */
    ~Order();

    /**
     * Add flowers to the order.
     */
    void addFlowers(const FlowerType& type, size_t count);

    /**
     * Set client name.
     */
    void setClient(std::string clientName);

    /**
     * Get client name.
     */
    std::string getClient() const;

    /**
     * Get flowers ordered for a type.
     */
    size_t getFlowersCount(const FlowerType& type) const;
};

typedef std::list<Order> OrderList;


#endif //PRIMAVERA_CONCURRENTE_ORDER_H
