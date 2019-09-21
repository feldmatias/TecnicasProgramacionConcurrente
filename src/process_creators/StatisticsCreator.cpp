
#include "StatisticsCreator.h"
#include "../statistics/Statistics.h"
#include "../concurrency/process/Process.h"

StatisticsCreator::StatisticsCreator() = default;

StatisticsCreator::~StatisticsCreator() = default;

ProcessInfoList StatisticsCreator::createStatistics() const {
    Statistics statistics;
    ProcessInfo processInfo = Process::create(statistics);
    if (processInfo.isChildProcess()) {
        return ProcessInfoList();
    }

    ProcessInfoList process;
    process.push_back(processInfo);
    return process;
}
