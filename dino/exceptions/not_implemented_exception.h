#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H
#include "platform.h"

#include <exception>
#include <stdexcept>

class NotImplementedExcepton : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

#define NOT_IMPLEMENTED() throw NotImplementedExcepton(DINO_PRETTY_FUNCTION);

#endif // NOT_IMPLEMENTED_EXCEPTION_H

