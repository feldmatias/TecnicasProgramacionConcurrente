

#include "DataSender.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../concurrency/Fifo.h"

void DataSender::sendData(const std::string &receiver, const std::string &header, const std::string &data) {
    WriteOnlyFile file(Fifo::filename(receiver));

    std::string line = header + DATA_HEADER_SEPARATOR + data;
    file.writeLine(line);
}

void DataSender::sendData(const std::string &receiver, const std::string &header) {
    sendData(receiver, header, "NO_DATA");
}