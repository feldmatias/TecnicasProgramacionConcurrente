

#ifndef PRIMAVERA_CONCURRENTE_CONFIGFILES_H
#define PRIMAVERA_CONCURRENTE_CONFIGFILES_H

class ConfigFiles {
private:
    static const std::string PATH;

public:
    static const std::string PRODUCERS;
    static const std::string DISTRIBUTION_CENTERS;
    static const std::string POINTS_OF_SALE;
};

const std::string ConfigFiles::PATH = "config/";
const std::string ConfigFiles::PRODUCERS = ConfigFiles::PATH + "producers.csv";
const std::string ConfigFiles::DISTRIBUTION_CENTERS = ConfigFiles::PATH + "distribution_centers.csv";
const std::string ConfigFiles::POINTS_OF_SALE = ConfigFiles::PATH + "points_of_sale.csv";

#endif //PRIMAVERA_CONCURRENTE_CONFIGFILES_H
