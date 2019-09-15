

#ifndef PRIMAVERA_CONCURRENTE_POINTOFSALE_H
#define PRIMAVERA_CONCURRENTE_POINTOFSALE_H


#include <string>
#include "Actor.h"
#include "../comunication/flowers/FlowerReceiver.h"
#include "../comunication/orders/OrderReceiver.h"

class PointOfSale : public Actor {
private:
    FlowerReceiver flowerReceiver;
    OrderReceiver orderReceiver;
    OrderList internetOrders;
    OrderList clients;

    /**
     * Receive flowers from distribution centers.
     */
    void receiveFlowers(const std::string& flowers);

    /**
     * Receive new clients.
     */
    void receiveClient(const std::string& client);

    /**
     * Receive new internet order.
     */
    void receiveInternetOrder(const std::string& order);

    /**
     * Attend clients one by one.
     */
    void attendClients();

    /**
     * Attend internet orders.
     */
    void attendInternetOrders();

    /**
     * Sell flowers to client.
     */
    void sellFlowersToClient(const Order &order);

    /**
     * Sell flowers to internet order.
     */
    void sellFlowersToInternet(const Order &order);

public:
    /**
     * Convert an index to point of sale name.
     */
    static std::string getName(int name);

    /**
     * Create a point of sale with a name.
     */
    explicit PointOfSale(const std::string& name);

    /**
     * Destructor.
     */
    ~PointOfSale() override;

    /**
     * Do point of sale's work.
     */
    void receiveData(Data data) override;

};


#endif //PRIMAVERA_CONCURRENTE_POINTOFSALE_H
