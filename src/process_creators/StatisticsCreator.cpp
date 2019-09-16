
#include "StatisticsCreator.h"
#include "../statistics/Statistics.h"
#include "../concurrency/Process.h"

StatisticsCreator::StatisticsCreator() = default;

StatisticsCreator::~StatisticsCreator() = default;

ProcessNames StatisticsCreator::createStatistics() const {
    Statistics statistics;
    if (Process::create(statistics)) {
        return ProcessNames();
    }

    ProcessNames processNames;
    processNames.push_back(statistics.name());
    return processNames;
}
