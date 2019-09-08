

#ifndef PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H
#define PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H


#include <string>
#include <unordered_map>

class ActorsConfig {
private:
    std::unordered_map<std::string, int> config;

public:
    ActorsConfig();

    ~ActorsConfig();

    int numberOfProducers() const;

    int producersBoxSize() const;

    int numberOfDistributionCenters() const;

    int numberOfPointsOfSale() const;
};


#endif //PRIMAVERA_CONCURRENTE_ACTORSCONFIG_H
