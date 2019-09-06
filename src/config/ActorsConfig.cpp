#include "ActorsConfig.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../../config/ConfigFiles.h"
#include "../utils/csv/CsvLine.h"

ActorsConfig::ActorsConfig() {
    ReadOnlyFile file(ACTORS_CONFIG);

    while (file.hasMoreData()) {
        std::string line = file.getLine();
        if (line.empty()) {
            continue;
        }

        CsvLine csv(line);
        std::string key = csv.getNext();
        config[key] = csv.getNextNumber();
    }

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

ActorsConfig::~ActorsConfig() = default;
