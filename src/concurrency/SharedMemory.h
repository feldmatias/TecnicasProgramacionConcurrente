
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
    explicit SharedMemory(const std::string& name, const T& defaultValue) {
        key_t key = std::hash<std::string>()(name);
        id = shmget(key, sizeof(T), 0644|IPC_CREAT);
        data = static_cast<T*>(shmat(id, NULL, 0));
        write(defaultValue);
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
