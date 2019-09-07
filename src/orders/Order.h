#ifndef PRIMAVERA_CONCURRENTE_ORDER_H
#define PRIMAVERA_CONCURRENTE_ORDER_H


#include <string>
#include <unordered_map>
#include "../flower/FlowerType.h"

class Order {
private:
    std::string client;
    std::unordered_map<FlowerType, size_t> orders;

public:
    explicit Order(std::string client);

    ~Order();

    void addFlowers(const FlowerType& type, size_t count);

    std::string getClient() const;

    size_t getFlowersCount(const FlowerType& type) const;
};


#endif //PRIMAVERA_CONCURRENTE_ORDER_H
