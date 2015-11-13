#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H

#include <exception>
#include <stdexcept>

class NotImplementedExcepton : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

#define NOT_IMPLEMENTED() throw NotImplementedExcepton(__PRETTY_FUNCTION__);

#endif // NOT_IMPLEMENTED_EXCEPTION_H

