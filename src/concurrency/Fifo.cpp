#include <sys/stat.h>

#include <memory>
#include <unistd.h>
#include "Fifo.h"

#define FIFO_EXTENSION ".fifo"

std::string Fifo::filename(const std::string& name) {
    return FIFO_EXTENSION + name + FIFO_EXTENSION;
}

Fifo::Fifo(const std::string &fileName) :
    name(filename(fileName)) {
    mknod(name.c_str(), S_IFIFO|0666, 0);
    file = std::make_unique<File>(name);
}

std::string Fifo::getLine() {
    return file->getLine();
}

Fifo::~Fifo() {
    unlink(name.c_str());
}
