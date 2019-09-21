#include <iostream>
#include <utility>
#include "InputReceiver.h"
#include "../DataSender.h"
#include "../../statistics/Statistics.h"

InputReceiver::InputReceiver(ProcessInfoList process) :
    process(std::move(process)) {
}

InputReceiver::~InputReceiver() = default;

void InputReceiver::start() {
    std::cout << "Ingrese '" << STATISTICS_CHAR << "' para ver estadisticas." << std::endl;
    std::cout << "Ingrese '" << EXIT_CHAR << "' para terminar." << std::endl;

    while (true) {
        int c = std::cin.get();
        if (c == EXIT_CHAR || c == EOF) {
            exit();
            return;
        }

        if (c == STATISTICS_CHAR) {
            showStatistics();
        }
    }
}

void InputReceiver::exit() {
    for (const ProcessInfo& childProcess : process) {
        DataSender::sendData(childProcess.getName(), EXIT);
    }
}

void InputReceiver::showStatistics() {
    DataSender::sendData(STATISTICS, SHOW_STATISTICS);
}

