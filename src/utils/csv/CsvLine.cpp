

#include "CsvLine.h"

const char CSV_SEPARATOR = ',';

CsvLine::CsvLine() = default;

CsvLine::CsvLine(const std::string& line) : line(line) {
}

std::string CsvLine::getNext() {
    std::string next;
    std::getline(line, next, CSV_SEPARATOR);
    return std::move(next);
}

void CsvLine::setNext(const std::string &element) {
    line << element << CSV_SEPARATOR;
}

std::string CsvLine::getCsv() const {
    return line.str();
}

CsvLine::~CsvLine() = default;
