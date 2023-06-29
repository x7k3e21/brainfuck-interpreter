
#include <stdint.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
using std::istream;
using std::ostream;

int32_t main(int32_t argc, char* argv[])
{
    std::cout << "You passed " << argc << " arguments" << std::endl;

    return EXIT_SUCCESS;
}