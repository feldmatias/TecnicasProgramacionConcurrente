#ifndef PRIMAVERA_CONCURRENTE_DATASENDER_H
#define PRIMAVERA_CONCURRENTE_DATASENDER_H


#include <string>

#define DATA_HEADER_SEPARATOR '@'

class DataSender {
public:

    /**
     * Send data to a receiver.
     */
    static void sendData(const std::string& receiver, const std::string& header, const std::string& data);

    /**
     * Send data to a receiver.
     */
    static void sendData(const std::string& receiver, const std::string& header);
};


#endif //PRIMAVERA_CONCURRENTE_DATASENDER_H
