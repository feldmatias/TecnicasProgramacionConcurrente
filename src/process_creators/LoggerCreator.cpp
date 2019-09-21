#include "LoggerCreator.h"
#include "../logger/Logger.h"
#include "../concurrency/Process.h"

LoggerCreator::LoggerCreator() = default;

ProcessInfoList LoggerCreator::createLogger() const {
    Logger logger;
    ProcessInfo processInfo = Process::create(logger);
    if (processInfo.isChildProcess()) {
        return ProcessInfoList();
    }

    ProcessInfoList process;
    process.push_back(processInfo);
    return process;
}

LoggerCreator::~LoggerCreator() = default;

