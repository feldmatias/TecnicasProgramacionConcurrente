

#ifndef PRIMAVERA_CONCURRENTE_CLIENTSCONFIG_H
#define PRIMAVERA_CONCURRENTE_CLIENTSCONFIG_H


#include "Config.h"

class ClientsConfig : public Config {
public:
    ClientsConfig();

    ~ClientsConfig() override;

    int minFlowerAmount() const;

    int maxFlowerAmount() const;

    int clientGeneratorRate() const;

};


#endif //PRIMAVERA_CONCURRENTE_CLIENTSCONFIG_H
