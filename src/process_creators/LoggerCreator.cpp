#include "LoggerCreator.h"
#include "../logger/Logger.h"
#include "../concurrency/Process.h"

LoggerCreator::LoggerCreator() = default;

ProcessNames LoggerCreator::createLogger() const {
    Logger logger;
    if (Process::create(logger)) {
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(logger.name());
    return processNames;
}

LoggerCreator::~LoggerCreator() = default;

