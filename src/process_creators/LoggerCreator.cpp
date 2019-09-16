#include <unistd.h>
#include "LoggerCreator.h"
#include "../logger/Logger.h"
#include "../concurrency/Process.h"

LoggerCreator::LoggerCreator() = default;

ProcessNames LoggerCreator::createLogger() const {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        Logger logger;
        Process process(logger);
        process.run();
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(LOG_FILE);
    return processNames;
}

LoggerCreator::~LoggerCreator() = default;

