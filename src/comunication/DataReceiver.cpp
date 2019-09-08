

#include "DataReceiver.h"
#include "../utils/file/WriteOnlyFile.h"

#define END_OF_BLOCK "END_OF_BLOCK"

DataReceiver::DataReceiver(const std::string& receiver) :
    fifo(receiver), receiver(receiver){
}

void DataReceiver::initializeReceiver() {
    // This allows to know if Fifo has new data or not.
    // Without this, there is no way to know if fifo has data, and getline() blocks
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(END_OF_BLOCK);
}

std::string DataReceiver::receiveNext() {
    std::string line = fifo.getLine();
    if (line == END_OF_BLOCK) {
        return "";
    }
    return line;
}

DataReceiver::~DataReceiver() = default;

