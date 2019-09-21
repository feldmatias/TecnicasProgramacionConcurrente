
#include <unistd.h>
#include "DataReceiverProcess.h"
#include "../../comunication/DataSender.h"
#include "../../utils/SystemCallException.h"

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
    pid_t pid = fork();
    if (pid < 0) {
        throw SystemCallException("fork");
    }

    if (pid == 0) {
        // Child process
        DataReceiverProcess process(runnable);
        process.run();
        return ProcessInfo::childProcess();
    }

    return ProcessInfo(pid, runnable.name());
}
