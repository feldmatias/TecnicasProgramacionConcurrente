

#ifndef PRIMAVERA_CONCURRENTE_WRITEONLYFILE_H
#define PRIMAVERA_CONCURRENTE_WRITEONLYFILE_H


#include "File.h"
#include <functional>

class WriteOnlyFile : public File {
public:
    /**
     * Open a write only file.
     */
    explicit WriteOnlyFile(const std::string& name);

    /**
     * Close the file.
     */
    ~WriteOnlyFile() override;

    /**
     * Remove the possibility to read a line.
     */
    std::string getLine() override {
        throw std::bad_function_call();
    }
};


#endif //PRIMAVERA_CONCURRENTE_WRITEONLYFILE_H
