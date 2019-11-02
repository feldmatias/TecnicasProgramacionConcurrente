#include "ReadOnlyFile.h"

ReadOnlyFile::ReadOnlyFile(const std::string &name) :
        File(name, std::fstream::in) {
}

ReadOnlyFile::~ReadOnlyFile() = default;
