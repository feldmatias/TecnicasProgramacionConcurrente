

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
    OrderList clients, internetOrders;

    /**
     * Receive flowers from distribution centers.
     */
    void receiveFlowers(const std::string& flowers);

    /**
     * Receive new clients.
     */
    void receiveClient(const std::string& client);

    /**
     * Attend the next client in queue.
     */
    void attendNextClient();

    /**
     * Attend next internet order in queue.
     */
    void attendInternetOrder();

    /**
     * Sell flowers to client.
     */
    void sellFlowersToClient(const Order &order, OrderList& orderList);

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
