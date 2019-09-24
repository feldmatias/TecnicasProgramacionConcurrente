#include "DataSender.h"
#include "../utils/file/WriteOnlyFile.h"
#include "../concurrency/fifos/Fifo.h"

void DataSender::sendData(const std::string &receiver, const std::string &header, const std::string &data) {
    std::string filename = Fifo::filename(receiver);

    if (!File::exists(filename)) {
        //Fifo does not exist
        return;
    }

    WriteOnlyFile file(filename);
    std::string line = header + DATA_HEADER_SEPARATOR + data;
    file.writeLine(line);
}

void DataSender::sendData(const std::string &receiver, const std::string &header) {
    sendData(receiver, header, "NO_DATA");
}
