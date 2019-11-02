

#include "ClientsConfig.h"
#include "../ConfigFiles.h"

ClientsConfig::ClientsConfig() : Config(CLIENTS_CONFIG) {
}

int ClientsConfig::minFlowerAmount() const {
    return config.at("min_flower_amount");
}

int ClientsConfig::maxFlowerAmount() const {
    return config.at("max_flower_amount");
}

int ClientsConfig::clientGeneratorRate() const {
    return config.at("client_generator_rate");
}

ClientsConfig::~ClientsConfig() = default;
