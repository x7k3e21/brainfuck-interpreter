
#ifndef OPTIONS_OPTION_H
#define OPTIONS_OPTION_H

#include <stdint.h>

#include <string>
using std::string;

namespace bf
{
    template <typename VALUE_TYPE>
    struct option
    {
        std::string name = "";
        VALUE_TYPE value = "";
    };
}

#endif