#include "ActorsConfig.h"
#include "../ConfigFiles.h"

ActorsConfig::ActorsConfig() : Config(ACTORS_CONFIG) {
}

int ActorsConfig::numberOfProducers() const {
    return config.at("number_of_producers");
}

int ActorsConfig::numberOfDistributionCenters() const {
    return config.at("number_of_centers");
}

int ActorsConfig::numberOfPointsOfSale() const {
    return config.at("number_of_sale_points");
}

int ActorsConfig::producersBoxSize() const {
    return config.at("producers_box_size");
}

int ActorsConfig::centersBoxSize() const {
    return config.at("centers_box_size");
}

ActorsConfig::~ActorsConfig() = default;
