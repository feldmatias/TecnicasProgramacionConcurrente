

#ifndef PRIMAVERA_CONCURRENTE_POINTOFSALE_H
#define PRIMAVERA_CONCURRENTE_POINTOFSALE_H


#include <string>
#include "Actor.h"
#include "../comunication/flowers/FlowerReceiver.h"
#include "../comunication/orders/OrderReceiver.h"

class PointOfSale : public Actor {
private:
    FlowerReceiver flowerReceiver;
    OrderReceiver clientReceiver;
    OrderList clients;

    /**
     * Receive flowers from distribution centers.
     */
    void receiveFlowers();

    /**
     * Receive new clients.
     */
    void receiveClients();

    /**
     * Attend the next client in queue.
     */
    void attendNextClient();

    /**
     * Sell flowers to a client.
     */
    void sellFlowersToClient(const Order& client);

public:
    /**
     * Convert an index to point of sale name.
     */
    static std::string getName(int name);

    /**
     * Convert an index to a point of sale name for a client.
     */
    static std::string getClientName(int name);

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
    void doWork() override;

    /**
     * Finish doing work.
     */
    void finish() override;
};


#endif //PRIMAVERA_CONCURRENTE_POINTOFSALE_H
