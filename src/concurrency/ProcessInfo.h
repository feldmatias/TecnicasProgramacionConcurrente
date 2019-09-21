#ifndef PRIMAVERA_CONCURRENTE_PROCESSINFO_H
#define PRIMAVERA_CONCURRENTE_PROCESSINFO_H


#include <fcntl.h>
#include <string>
#include <list>


class ProcessInfo {
private:
    pid_t pid;
    std::string name;
    bool isDataReceiver;

public:
    /**
     * Child process info.
     */
    static ProcessInfo childProcess();

    /**
     * Constructor.
     */
    ProcessInfo(pid_t pid, std::string name, bool isDataReceiver = true);

    /**
     * Destructor
     */
    ~ProcessInfo();

    /**
     * Get pid.
     */
    pid_t getPid() const;

    /**
     * Get name.
     */
    std::string getName() const;

    /**
     * If receives data.
     */
    bool receivesData() const;

    /**
     * If is child process.
     */
    bool isChildProcess() const;
};

typedef std::list<ProcessInfo> ProcessInfoList;


#endif //PRIMAVERA_CONCURRENTE_PROCESSINFO_H
