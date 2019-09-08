

#ifndef PRIMAVERA_CONCURRENTE_READONLYFILE_H
#define PRIMAVERA_CONCURRENTE_READONLYFILE_H


#include "File.h"
#include <functional>

class ReadOnlyFile: public File {
public:
    /**
     * Open a read only file.
     */
    explicit ReadOnlyFile(const std::string& name);

    /**
     * Close the file.
     */
    ~ReadOnlyFile() override;

    /**
     * Remove the possibility to write a line.
     */
    void writeLine(const std::string &line) override {
        throw std::bad_function_call();
    }

};


#endif //PRIMAVERA_CONCURRENTE_READONLYFILE_H
