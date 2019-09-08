

#include <chrono>
#include <thread>
#include "Process.h"

#define CPU_SAVE_SLEEP 50

Process::Process(Runnable &runnable) :
    runnable(runnable) {
}

Process::~Process() = default;

void Process::run() {
    while (!exitComunicator.shouldExit()) {
        runnable.doWork();

        // Sleep to avoid cpu work at 100%
        std::this_thread::sleep_for(std::chrono::milliseconds(CPU_SAVE_SLEEP));
    }

    runnable.finish();
}
