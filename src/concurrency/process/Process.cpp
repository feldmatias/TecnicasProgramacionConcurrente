#include <unistd.h>
#include "Process.h"
#include "../../utils/SystemCallException.h"

pid_t Process::create() {
    pid_t pid = fork();
    if (pid < 0) {
        throw SystemCallException("fork");
    }
    return pid;
}
