
#ifndef BFI_MEMORY_MEMORY_H
#define BFI_MEMORY_MEMORY_H

#include <stddef.h>
#include <stdint.h>

#include <sys/types.h>

#include <array>
using std::array;

namespace bf
{
    template <typename T=uint32_t, size_t n=30000>
    class Memory
    {
        public:

        Memory();
        virtual ~Memory() = default;

        inline void IncrementValue(T offset);
        inline void DecrementValue(T offset);

        inline void MoveForward(ssize_t offset);
        inline void MoveBackward(ssize_t offset);

        private:

        std::array<T, n> memory_;
    };
}

#endif