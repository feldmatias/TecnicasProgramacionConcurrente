
#include <chrono>
#include <thread>
#include "Process.h"
#include "../comunication/DataSender.h"

#define NO_DATA_SENT "NO_DATA"

Process::Process(Runnable &runnable) :
    runnable(runnable), receiver(runnable.name()) {
}

Process::~Process() = default;

void Process::run() {
    while (true) {
        if (!runnable.receivesData()) {
            // This to avoid process which does not expect data to block.
            DataSender::sendData(runnable.name(), NO_DATA_SENT);

            //Simulate time passed
            //TODO move this out of here
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }

        Data data = receiver.receiveNext();
        if (data.getHeader() == EXIT) {
            return;
        }

        runnable.receiveData(data);
    }
}
