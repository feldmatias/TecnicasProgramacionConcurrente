#include <unistd.h>
#include "DataSenderProcess.h"
#include "../signals/SignalHandler.h"
#include "Process.h"

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
    pid_t pid = Process::create();

    if (pid == 0) {
        // Child process
        DataSenderProcess process(runnable);
        process.run();
        return ProcessInfo::childProcess();
    }

    return ProcessInfo(pid, runnable.name(), false);
}

DataSenderProcess::~DataSenderProcess() = default;
