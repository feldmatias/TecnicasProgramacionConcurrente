
#include "StatisticsCreator.h"
#include "../statistics/Statistics.h"
#include "../concurrency/process/DataReceiverProcess.h"

StatisticsCreator::StatisticsCreator() = default;

StatisticsCreator::~StatisticsCreator() = default;

ProcessInfoList StatisticsCreator::createStatistics() const {
    Statistics statistics;
    ProcessInfo processInfo = DataReceiverProcess::create(statistics);
    if (processInfo.isChildProcess()) {
        return ProcessInfoList();
    }

    ProcessInfoList process;
    process.push_back(processInfo);
    return process;
}
