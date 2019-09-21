#include <unistd.h>
#include "DataSenderProcess.h"
#include "../signals/SignalHandler.h"
#include "../../utils/SystemCallException.h"

DataSenderProcess::DataSenderProcess(Runnable &runnable) :
    runnable(runnable) {
    SignalHandler::getInstance().registerSignalEvent(ExitSignalEventHandler::signum(), &exitHandler);
}

void DataSenderProcess::run() {
    while (!exitHandler.shouldQuit()) {
        runnable.doWork(Data());
    }
}

ProcessInfo DataSenderProcess::create(Runnable &runnable) {
    pid_t pid = fork();
    if (pid < 0) {
        throw SystemCallException("fork");
    }

    if (pid == 0) {
        // Child process
        DataSenderProcess process(runnable);
        process.run();
        return ProcessInfo::childProcess();
    }

    return ProcessInfo(pid, runnable.name(), false);
}

DataSenderProcess::~DataSenderProcess() = default;
