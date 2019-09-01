

#ifndef PRIMAVERA_CONCURRENTE_READONLYFILE_H
#define PRIMAVERA_CONCURRENTE_READONLYFILE_H


#include "File.h"

class ReadOnlyFile: public File {
public:

    explicit ReadOnlyFile(const std::string& name);

    ~ReadOnlyFile() override;

    void writeLine(const std::string &line) override;

};


#endif //PRIMAVERA_CONCURRENTE_READONLYFILE_H
