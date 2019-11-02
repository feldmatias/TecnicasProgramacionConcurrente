

#include "Config.h"
#include "../utils/file/ReadOnlyFile.h"
#include "../utils/csv/CsvLine.h"

Config::Config(const std::string &configFile) {
    ReadOnlyFile file(configFile);

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

Config::~Config() = default;
