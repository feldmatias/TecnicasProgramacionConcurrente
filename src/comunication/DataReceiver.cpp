

#include <sstream>
#include "DataReceiver.h"
#include "DataSender.h"

#define END_OF_BLOCK "END_OF_BLOCK"

DataReceiver::DataReceiver(const std::string& receiver) :
    fifo(receiver) {
}

/*void DataReceiver::initializeReceiver() {
    // This allows to know if Fifo has new data or not.
    // Without this, there is no way to know if fifo has data, and getline() blocks
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(END_OF_BLOCK);
}**/

Data DataReceiver::receiveNext() {
    std::stringstream line(fifo.getLine());

    std::string header;
    std::string data;

    std::getline(line, header, DATA_HEADER_SEPARATOR);
    std::getline(line, data, DATA_HEADER_SEPARATOR);

    return Data(header, data);
}

DataReceiver::~DataReceiver() = default;

