

#include <functional>
#include "ReadOnlyFile.h"

ReadOnlyFile::ReadOnlyFile(const std::string &name) :
    File(name, std::fstream::in) {
}

void ReadOnlyFile::writeLine(const std::string &line) {
    throw std::bad_function_call();
}

ReadOnlyFile::~ReadOnlyFile() = default;
