#ifndef UTILS
#define UTILS

#include <cstring>
#include <string>
#include <memory>

namespace utils {

template<class ...Args>
std::string format(const char* format, Args... args) {
    std::unique_ptr<char[]> buf;

    int final_len = 0;
    int len = strlen(format) * 2;

    while(1) {
        buf.reset(new char[len]);
        final_len = snprintf(buf.get(), len, format, args...);

        if (final_len >= len) {
            len += final_len - len + 1;
        } else {
            break;
        }
    }

    return std::string(buf.get());
}
}

#endif // UTILS

