

#ifndef PRIMAVERA_CONCURRENTE_WRITEONLYFILE_H
#define PRIMAVERA_CONCURRENTE_WRITEONLYFILE_H


#include "File.h"

class WriteOnlyFile : public File {
public:
    explicit WriteOnlyFile(const std::string& name);

    ~WriteOnlyFile();

    virtual std::string getLine() override;
};


#endif //PRIMAVERA_CONCURRENTE_WRITEONLYFILE_H
