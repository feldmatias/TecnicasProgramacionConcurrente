

#include "ClientsConfig.h"
#include "../../config/ConfigFiles.h"

ClientsConfig::ClientsConfig(std::string clientConfigFile) : Config(clientConfigFile) {
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
