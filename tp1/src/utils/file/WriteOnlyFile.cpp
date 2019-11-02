
#include "WriteOnlyFile.h"

WriteOnlyFile::WriteOnlyFile(const std::string &name) :
        File(name, std::fstream::out | std::fstream::trunc) {
}

WriteOnlyFile::~WriteOnlyFile() = default;
