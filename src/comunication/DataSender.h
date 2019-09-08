#ifndef PRIMAVERA_CONCURRENTE_DATASENDER_H
#define PRIMAVERA_CONCURRENTE_DATASENDER_H


#include <string>

class DataSender {
protected:
    void sendData(const std::string& receiver, const std::string& data) const;

public:
    DataSender();

    ~DataSender();
};


#endif //PRIMAVERA_CONCURRENTE_DATASENDER_H
