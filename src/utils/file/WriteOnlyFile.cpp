

#include <functional>
#include "WriteOnlyFile.h"

WriteOnlyFile::WriteOnlyFile(const std::string &name) :
    File(name, std::fstream::out){
}

std::string WriteOnlyFile::getLine() {
    throw std::bad_function_call();
}

WriteOnlyFile::~WriteOnlyFile() = default;
