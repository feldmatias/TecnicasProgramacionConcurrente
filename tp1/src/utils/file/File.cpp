#include <bits/ios_base.h>
#include "File.h"

#define LINE_SEPARATOR '\n'

File::File(const std::string &name, std::ios_base::openmode mode) :
        file(name, mode) {
}

File::~File() = default;

void File::writeLine(const std::string &line) {
    std::string newLine = line + LINE_SEPARATOR;
    file << newLine;
}

std::string File::getLine() {
    std::string line;
    std::getline(file, line, LINE_SEPARATOR);
    return std::move(line);
}

bool File::hasMoreData() {
    // This method does not work with fifo
    return !file.eof() && file.peek() != EOF;
}

bool File::exists(const std::string &filename) {
    return (bool) std::ifstream(filename);
}
