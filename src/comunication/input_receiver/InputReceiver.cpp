#include <iostream>
#include <utility>
#include "InputReceiver.h"
#include "../DataSender.h"
#include "../../statistics/Statistics.h"
#include "../../concurrency/signals/ExitSignalEventHandler.h"
#include "../../concurrency/process/DataReceiverProcess.h"
#include "../../concurrency/signals/SignalHandler.h"

InputReceiver::InputReceiver(ProcessInfoList process) :
    process(std::move(process)) {
}

InputReceiver::~InputReceiver() = default;

void InputReceiver::start() {
    std::cout << "Ingrese '" << STATISTICS_CHAR << "' para ver estadisticas." << std::endl;
    std::cout << "Ingrese '" << EXIT_CHAR << "' para terminar." << std::endl;
    std::cout << std::endl;

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
        if (childProcess.receivesData()) {
            DataSender::sendData(childProcess.getName(), EXIT);
        } else {
            SignalHandler::sendSignal(childProcess.getPid(), ExitSignalEventHandler::signum());
        }
    }
}

void InputReceiver::showStatistics() {
    DataSender::sendData(STATISTICS, SHOW_STATISTICS);
}

