#ifndef PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H
#define PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H


#include "../concurrency/Runnable.h"
#include "../config/ClientsConfig.h"
#include "Order.h"
#include "../config/ActorsConfig.h"
#include "../comunication/orders/OrderSender.h"

#define CLIENT_NAME std::string("Client")

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
    void doWork() override;

    /**
     * Stop working.
     */
    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H
