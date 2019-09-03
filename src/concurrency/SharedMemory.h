
#ifndef PRIMAVERA_CONCURRENTE_SHAREDMEMORY_H
#define PRIMAVERA_CONCURRENTE_SHAREDMEMORY_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>

template <class T> class SharedMemory {
private:
    int id;
    T* data;

public:
    explicit SharedMemory(const std::string& name) {
        key_t key = ftok(name.c_str(), 1);
        id = shmget(key, sizeof(T), 0644|IPC_CREAT);
        data = shmat(id, NULL, 0);
    }

    ~SharedMemory() {
        shmdt(data);
        shmctl(id, IPC_RMID, NULL);
    }

    void write(const T& info) {
        *data = info;
    }

    T read() const {
        return *data;
    }

};


#endif //PRIMAVERA_CONCURRENTE_SHAREDMEMORY_H
