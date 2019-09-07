

#include "DataSender.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../concurrency/Fifo.h"

DataSender::DataSender() = default;

DataSender::~DataSender() = default;

void DataSender::sendData(const std::string &receiver, const std::string &data) const {
    WriteOnlyFile file(Fifo::filename(receiver));
    file.writeLine(data);
}
