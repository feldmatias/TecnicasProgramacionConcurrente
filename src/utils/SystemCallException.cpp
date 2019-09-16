

#include <cstring>
#include <utility>
#include <sstream>
#include "SystemCallException.h"

SystemCallException::SystemCallException(std::string function) :
    function(std::move(function)), msg(std::strerror(errno)) {
}

const char *SystemCallException::what() const noexcept {
    return message().c_str();
}

std::string SystemCallException::message() const {
    std::stringstream error;
    error << "Error en " << function << ": ";
    error << msg;
    return error.str();
}

SystemCallException::~SystemCallException() = default;
