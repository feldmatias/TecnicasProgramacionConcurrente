//
// Created by guille on 13/9/19.
//

#ifndef PRIMAVERA_CONCURRENTE_INTERNETORDERRECEIVER_H
#define PRIMAVERA_CONCURRENTE_INTERNETORDERRECEIVER_H


#include <list>
#include "../DataReceiver.h"
#include "../../orders/Order.h"
#include "../../utils/file/ReadOnlyFile.h"
#include "../../utils/csv/CsvLine.h"

class InternetOrderReceiver {
protected:
    ReadOnlyFile ordersFile;
    int clientNumber;
    std::string name;
public:

    explicit InternetOrderReceiver(const std::string& receiver, std::string name);

    virtual ~InternetOrderReceiver();

    /**
     * Receive all internet orders
     */
    std::list<Order> receiveOrders();

    /**
     * Processes an order
     */
    Order processOrder(std::string info);
};


#endif //PRIMAVERA_CONCURRENTE_INTERNETORDERRECEIVER_H
