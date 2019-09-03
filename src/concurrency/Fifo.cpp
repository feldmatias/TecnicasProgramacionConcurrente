

#include <sys/stat.h>

#include <memory>
#include <unistd.h>
#include "Fifo.h"

Fifo::Fifo(const std::string &fileName) :
    name(fileName + FIFO_EXTENSION) {
    mknod(name.c_str(), S_IFIFO|0666, 0);
    file = std::make_unique<File>(name);
}

std::string Fifo::getLine() {
    return file->getLine();
}

bool Fifo::hasData() {
    return file->hasMoreData();
}

Fifo::~Fifo() {
    unlink(name.c_str());
}
