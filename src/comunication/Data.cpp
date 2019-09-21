

#include "Data.h"

#include <utility>

Data::Data(std::string header, std::string data) :
    header(std::move(header)), data(std::move(data)) {
}

std::string Data::getHeader() const {
    return header;
}

std::string Data::getData() const {
    return data;
}

Data::Data() = default;

Data::~Data() = default;
