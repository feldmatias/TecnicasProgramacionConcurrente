

#include <thread>
#include "TimeSimulator.h"

#define TIME_TO_SIMULATE 25

void TimeSimulator::simulate() {
    std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_SIMULATE));
}
