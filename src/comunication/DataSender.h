#ifndef PRIMAVERA_CONCURRENTE_DATASENDER_H
#define PRIMAVERA_CONCURRENTE_DATASENDER_H


#include <string>

class DataSender {
protected:
    /**
     * Send data to a receiver.
     */
    void sendData(const std::string& receiver, const std::string& data) const;

public:
    /**
     * Constructor.
     */
    DataSender();

    /**
     * Destructor.
     */
    virtual ~DataSender();
};


#endif //PRIMAVERA_CONCURRENTE_DATASENDER_H
