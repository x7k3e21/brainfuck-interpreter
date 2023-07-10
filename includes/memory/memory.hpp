
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

        Memory() : memory_(), iterator_(memory_.begin()) { };

        virtual ~Memory() = default;

        inline void IncrementValue(T offset) { *this->iterator_ += offset; };
        inline void DecrementValue(T offset) { *this->iterator_ -= offset; };

        inline void MoveForward(ssize_t offset) { this->iterator_ += offset; };
        inline void MoveBackward(ssize_t offset) { this->iterator_ -= offset; };

        inline T ReadValue() const { return *this->iterator_; }

        private:

        std::array<T, n> memory_;
        typename decltype(memory_)::iterator iterator_; 
    };
}

#endif