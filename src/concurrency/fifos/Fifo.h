
#ifndef PRIMAVERA_CONCURRENTE_FIFO_H
#define PRIMAVERA_CONCURRENTE_FIFO_H

#include <string>
#include <memory>
#include "../../utils/file/File.h"

#define FIFO_FOLDER "fifo"

class Fifo {
private:
    std::string name;
    std::unique_ptr<File> file;

public:
    /**
     * Convert a name to a fifo filename.
     */
    static std::string filename(const std::string& name);

    /**
     * Delete a fifo.
     */
    static void remove(const std::string& name);

    /**
     * Create a Fifo with a name.
     */
    explicit Fifo(const std::string& name);

    /**
     * Delete the fifo.
     */
    ~Fifo();

    /**
     * Get next line sent through the fifo.
     */
    std::string getLine();
};


#endif //PRIMAVERA_CONCURRENTE_FIFO_H
