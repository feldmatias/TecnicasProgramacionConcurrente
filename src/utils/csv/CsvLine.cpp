
#include <algorithm>
#include "CsvLine.h"

const char CSV_SEPARATOR = ',';

CsvLine::CsvLine() = default;

CsvLine::CsvLine(const std::string &line) : line(line) {
}

std::string CsvLine::getCsv() const {
    return line.str();
}

std::string CsvLine::getNext() {
    std::string next;
    std::getline(line, next, CSV_SEPARATOR);
    next.erase(std::remove(next.begin(), next.end(), ' '), next.end());
    return std::move(next);
}

void CsvLine::setNext(const std::string &element) {
    line << element << CSV_SEPARATOR;
}

int CsvLine::getNextNumber() {
    std::string next = getNext();
    return std::stoi(next);
}

void CsvLine::setNext(const int element) {
    line << element << CSV_SEPARATOR;
}

CsvLine::~CsvLine() = default;
