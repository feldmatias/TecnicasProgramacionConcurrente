#include <unistd.h>
#include "LoggerCreator.h"
#include "../logger/Logger.h"
#include "../concurrency/Process.h"

LoggerCreator::LoggerCreator() = default;

bool LoggerCreator::createLogger() const {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        Logger logger;
        Process process(logger);
        process.run();
        return true;
    }
    return false;
}

LoggerCreator::~LoggerCreator() = default;

