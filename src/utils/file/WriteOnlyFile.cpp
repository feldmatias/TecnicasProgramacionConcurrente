
#include "WriteOnlyFile.h"

WriteOnlyFile::WriteOnlyFile(const std::string &name) :
    File(name, std::fstream::out){
}

WriteOnlyFile::~WriteOnlyFile() = default;
