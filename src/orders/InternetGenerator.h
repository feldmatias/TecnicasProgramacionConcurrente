

#ifndef PRIMAVERA_CONCURRENTE_INTERNETGENERATOR_H
#define PRIMAVERA_CONCURRENTE_INTERNETGENERATOR_H

#include "../concurrency/Runnable.h"
#include "../config/ActorsConfig.h"
#include "../config/ClientsConfig.h"
#include "../comunication/orders/OrderSender.h"

#define INTERNET_NAME std::string("Internet")

#define INTERNET_GENERATOR "InternetGenerator"

class InternetGenerator : public Runnable {
private:
    ActorsConfig actorsConfig;
    ClientsConfig config;
    OrderSender orderSender;
    OrderList orders;

    int lastOrder;

    /**
     * Initialize orders.
     */
     void initializeOrders();

    /**
     * Send order to a point of sale.
     */
    void sendOrder();

public:
    /**
     * Constructor.
     */
    InternetGenerator();

    /**
     * Destructor.
     */
    ~InternetGenerator() override;

    /**
     * Generate internet orders.
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


#endif //PRIMAVERA_CONCURRENTE_INTERNETGENERATOR_H
