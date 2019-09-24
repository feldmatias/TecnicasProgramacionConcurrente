
#include <unistd.h>
#include "DataReceiverProcess.h"
#include "Process.h"

DataReceiverProcess::DataReceiverProcess(Runnable &runnable) :
    runnable(runnable), receiver(runnable.name()) {
}

DataReceiverProcess::~DataReceiverProcess() = default;

void DataReceiverProcess::run() {
    while (true) {
        Data data = receiver.receiveNext();
        if (data.getHeader() == EXIT) {
            return;
        }

        runnable.doWork(data);
    }
}

ProcessInfo DataReceiverProcess::create(Runnable &runnable) {
    DataReceiverProcess process(runnable);

    pid_t pid = Process::create();

    if (pid == 0) {
        // Child process
        process.run();
        Fifo::remove(runnable.name());
        return ProcessInfo::childProcess();
    }

    return ProcessInfo(pid, runnable.name());
}
