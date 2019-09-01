#include <iostream>
#include "src/utils/file/File.h"
#include "src/utils/csv/CsvLine.h"

int main() {
    {
        CsvLine line;
        line.setNext(std::string("hola"));
        line.setNext("como");
        line.setNext("te");
        line.setNext("va");
        line.setNext(5);

        File file("test");
        file.writeLine(line.getCsv());
        file.writeLine(line.getCsv());
    }

    {
        File file("test");
        std::cout << file.getLine() << std::endl << std::endl;

        CsvLine output(file.getLine());
        std::cout << "Element 1  - " << output.getNext() << std::endl;
        std::cout << "Element 2  - " << output.getNext() << std::endl;
        std::cout << "Element 3  - " << output.getNext() << std::endl;
        std::cout << "Element 4  - " << output.getNext() << std::endl;
        std::cout << "Element 5  - " << output.getNextNumber() + 1 << std::endl;
        std::cout << "Element 6  - " << output.getNext() << std::endl;
        std::cout << "Element 7  - " << output.getNext() << std::endl;
    }

    remove("test");

    return 0;
}