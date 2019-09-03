

#include <chrono>
#include <thread>
#include "Process.h"

Process::Process(Runnable &runnable) :
    runnable(runnable) {
}

Process::~Process() = default;

void Process::run() {
    while (!exitComunicator.isExit()) {
        runnable.doWork();

        // Sleep to avoid cpu work at 100%
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    runnable.finish();
}
