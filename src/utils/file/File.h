#ifndef PRIMAVERA_CONCURRENTE_FILE_H
#define PRIMAVERA_CONCURRENTE_FILE_H


#include <string>
#include <fstream>

class File {

private:
    std::fstream file;

public:
    /**
     * Open a file in mode.
     */
    explicit File(const std::string& name,
            std::ios_base::openmode mode = std::fstream::in | std::fstream::out | std::fstream::app);

    /**
     * Close the file.
     */
    virtual ~File();

    /**
     * Get next line written in file.
     */
    virtual std::string getLine();

    /**
     * Write a line to the file.
     */
    virtual void writeLine(const std::string &line);

    /**
     * If file has more data to read.
     */
    bool hasMoreData();
};


#endif //PRIMAVERA_CONCURRENTE_FILE_H
