
#ifndef PRIMAVERA_CONCURRENTE_CONFIG_H
#define PRIMAVERA_CONCURRENTE_CONFIG_H


#include <unordered_map>

class Config {
protected:
    std::unordered_map<std::string, int> config;

public:
    explicit Config(const std::string& configFile);

    virtual ~Config();
};


#endif //PRIMAVERA_CONCURRENTE_CONFIG_H
