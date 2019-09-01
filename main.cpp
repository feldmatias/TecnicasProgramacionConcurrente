#include <iostream>
#include "src/utils/file/File.h"

int main() {
    File file(".gitignore");
    while (file.hasMoreData()) {
        std::cout << "Line  - " << file.getLine() << std::endl;
    }
    return 0;
}