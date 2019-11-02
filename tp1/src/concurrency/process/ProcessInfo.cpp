

#include "ProcessInfo.h"

#include <utility>

#define CHILD_PID -1

ProcessInfo::ProcessInfo(pid_t pid, std::string name, bool isDataReceiver) :
        pid(pid), name(std::move(name)), isDataReceiver(isDataReceiver) {
}

pid_t ProcessInfo::getPid() const {
    return pid;
}

std::string ProcessInfo::getName() const {
    return name;
}

bool ProcessInfo::receivesData() const {
    return isDataReceiver;
}

ProcessInfo ProcessInfo::childProcess() {
    return ProcessInfo(CHILD_PID, "child", false);
}

bool ProcessInfo::isChildProcess() const {
    return pid == CHILD_PID;
}

ProcessInfo::~ProcessInfo() = default;
