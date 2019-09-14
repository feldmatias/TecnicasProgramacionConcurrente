

#ifndef PRIMAVERA_CONCURRENTE_SYSTEMCALLEXCEPTION_H
#define PRIMAVERA_CONCURRENTE_SYSTEMCALLEXCEPTION_H


#include <string>

class SystemCallException : public std::exception {
private:
    std::string function;
    std::string msg;

public:
    /**
     * Constructor.
     */
    explicit SystemCallException(std::string function);

    /**
     * Destructor.
     */
    ~SystemCallException() override;

    /**
     * Exception message.
     */
    const char* what() const noexcept override;

    /**
     * Exception message.
     */
    std::string message() const;
};


#endif //PRIMAVERA_CONCURRENTE_SYSTEMCALLEXCEPTION_H
