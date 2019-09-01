#ifndef PRIMAVERA_CONCURRENTE_FILE_H
#define PRIMAVERA_CONCURRENTE_FILE_H


#include <string>
#include <fstream>

class File {

private:
    std::fstream file;

public:

    explicit File(const std::string& name,
            std::ios_base::openmode mode = std::fstream::in | std::fstream::out | std::fstream::app);

    virtual ~File();

    virtual std::string getLine();

    virtual void writeLine(const std::string &line);

    bool hasMoreData();
};


#endif //PRIMAVERA_CONCURRENTE_FILE_H
