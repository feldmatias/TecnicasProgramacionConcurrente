#include <bits/ios_base.h>
#include <iostream>
#include "File.h"

const char LINE_SEPARATOR = '\n';

File::File(const std::string& name, std::ios_base::openmode mode) :
    file(name, mode) {
}

File::~File() = default;

void File::writeLine(const std::string& line) {
    std::string newLine = line + LINE_SEPARATOR;
    file << newLine;
}

std::string File::getLine() {
    std::string line;
    std::getline(file, line, LINE_SEPARATOR);
    return std::move(line);
}

bool File::hasMoreData() {
    return !file.eof() && file.peek() != EOF;
}
