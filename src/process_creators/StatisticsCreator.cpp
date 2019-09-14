

#include <unistd.h>
#include "StatisticsCreator.h"
#include "../statistics/Statistics.h"
#include "../concurrency/Process.h"

StatisticsCreator::StatisticsCreator() = default;

StatisticsCreator::~StatisticsCreator() = default;

ProcessNames StatisticsCreator::createStatistics() const {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        Statistics statistics;
        Process process(statistics);
        process.run();
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(STATISTICS);
    return processNames;
}
