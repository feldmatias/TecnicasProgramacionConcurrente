
#include <iostream>
#include "PrimaveraConcurrente.h"
#include "utils/SystemCallException.h"

#define EXIT_OK 0
#define EXIT_ERROR 1

int main() {

    try {
        PrimaveraConcurrente program;
        program.start();
        return EXIT_OK;
    } catch (SystemCallException &exception) {
        std::cerr << exception.message() << std::endl;
        return EXIT_ERROR;
    }
}