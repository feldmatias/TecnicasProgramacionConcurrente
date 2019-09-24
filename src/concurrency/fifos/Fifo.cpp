#include <sys/stat.h>
#include <unistd.h>

#include "Fifo.h"
#include "../../utils/SystemCallException.h"

#define FIFO_EXTENSION ".fifo"

std::string Fifo::filename(const std::string &name) {
    return FIFO_FOLDER + std::string("/") + name + FIFO_EXTENSION;
}

Fifo::Fifo(const std::string &fileName) :
        name(filename(fileName)) {
    if (mknod(name.c_str(), S_IFIFO | 0666, 0) < 0) {
        throw SystemCallException("mknod");
    }
    file = std::make_unique<File>(name);
}

std::string Fifo::getLine() {
    return file->getLine();
}

void Fifo::remove(const std::string &name) {
    unlink(filename(name).c_str());
}

Fifo::~Fifo() = default;
