#ifndef PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H
#define PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H


#include "../concurrency/Runnable.h"
#include "../config/ClientsConfig.h"
#include "Order.h"
#include "../config/ActorsConfig.h"
#include "../comunication/orders/OrderSender.h"

#define CLIENT_NAME std::string("Client")
#define INTERNET_NAME std::string("Internet-order")

#define CLIENTS_GENERATOR "ClientsGenerator"

class ClientGenerator : public Runnable {
private:
    ActorsConfig actorsConfig;
    ClientsConfig config;
    OrderSender clientSender;

    int lastClient;
    std::string clientName;

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
    explicit ClientGenerator(std::string clientConfigFile);

    /**
     * Destructor.
     */
    ~ClientGenerator() override;

    /**
     * Generate clients.
     */
    void receiveData() override;

    /**
     * Get name.
     */
    std::string name() override;
};


#endif //PRIMAVERA_CONCURRENTE_CLIENTGENERATOR_H
