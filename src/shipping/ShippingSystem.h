

#ifndef PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEM_H
#define PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEM_H


#include "../concurrency/Runnable.h"
#include "../comunication/flowers/FlowerReceiver.h"

#define SHIPPING_SYSTEM "ServicioDeEnvios"

class ShippingSystem : public Runnable {
private:
    FlowerReceiver receiver;

public:
    /**
     * Send transaction to shipping system.
     */
    static void sendTransaction(const FlowerTransaction& transaction);

    /**
     * Constructor.
     */
    ShippingSystem();

    /**
     * Destructor.
     */
    ~ShippingSystem() override;

    /**
     * Receive transactions.
     */
    void receiveData(Data data) override;

    /**
     * Get name.
     */
    std::string name() override;
};


#endif //PRIMAVERA_CONCURRENTE_SHIPPINGSYSTEM_H
