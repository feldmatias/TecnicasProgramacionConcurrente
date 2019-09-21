#ifndef PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H
#define PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H


#include "../concurrency/process/Runnable.h"
#include "../config/ClientsConfig.h"
#include "Order.h"
#include "../config/ActorsConfig.h"
#include "../comunication/orders/OrderSender.h"

#define CLIENT_NAME std::string("Cliente")

#define CLIENTS_GENERATOR "ClientsGenerator"

class ClientGenerator : public Runnable {
private:
    ActorsConfig actorsConfig;
    ClientsConfig config;
    OrderSender clientSender;

    int lastClient;

    /**
     * Create a new client.
     */
    Order createClient();

    /**
     * Send client to a point of sale.
     */
    void sendClient(const Order& client);

public:
    /**
     * Constructor.
     */
    ClientGenerator();

    /**
     * Destructor.
     */
    ~ClientGenerator() override;

    /**
     * Generate clients.
     */
    void receiveData(Data data) override;

    /**
     * Get name.
     */
    std::string name() override;

    /**
      * If receives data from other process.
      */
    bool receivesData() override {
        return false;
    }
};


#endif //PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H
