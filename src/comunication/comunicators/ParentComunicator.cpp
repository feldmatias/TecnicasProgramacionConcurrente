

#include <iostream>
#include "ParentComunicator.h"

ParentComunicator::ParentComunicator() = default;

ParentComunicator::~ParentComunicator() = default;

void ParentComunicator::start() {
    std::cout << "Ingrese '" << STATISTICS_CHAR << "' para ver estadisticas." << std::endl;
    std::cout << "Ingrese '" << EXIT_CHAR << "' para terminar." << std::endl;

    while (true) {
        int c = std::cin.get();
        if (c == EXIT_CHAR || c == EOF) {
            exitComunicator.setExit();
            return;
        }

        if (c == STATISTICS_CHAR) {
            //statisticsComunicator.showStatistics();
            std::cout << "estadisticas...." << std::endl;
        }
    }
}
