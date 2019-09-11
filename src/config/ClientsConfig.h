

#ifndef PRIMAVERA_CONCURRENTE_CLIENTSCONFIG_H
#define PRIMAVERA_CONCURRENTE_CLIENTSCONFIG_H


#include "Config.h"

class ClientsConfig : public Config {
public:
    /**
     * Constructor.
     */
    ClientsConfig(std::string clientConfigFile);

    /**
     * Destructor.
     */
    ~ClientsConfig() override;

    /**
     * Get min amount flowers that a client can buy.
     */
    int minFlowerAmount() const;

    /**
     * Get max amount flowers that a client can buy.
     */
    int maxFlowerAmount() const;

    /**
     * Get the rate in which the clients are generated.
     */
    int clientGeneratorRate() const;

};


#endif //PRIMAVERA_CONCURRENTE_CLIENTSCONFIG_H
