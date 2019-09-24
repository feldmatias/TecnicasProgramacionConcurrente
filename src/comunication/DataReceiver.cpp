
#include <sstream>
#include "DataReceiver.h"
#include "DataSender.h"


DataReceiver::DataReceiver(const std::string &receiver) :
        fifo(receiver) {
}

Data DataReceiver::receiveNext() {
    std::stringstream line(fifo.getLine());

    std::string header;
    std::string data;

    std::getline(line, header, DATA_HEADER_SEPARATOR);
    std::getline(line, data, DATA_HEADER_SEPARATOR);

    return Data(header, data);
}

DataReceiver::~DataReceiver() = default;

