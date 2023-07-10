
/*!
    \file
    \brief
 */

#ifndef BFI_MEMORY_MEMORY_H
#define BFI_MEMORY_MEMORY_H

#include <stddef.h>
#include <stdint.h>

#include <sys/types.h>

#include <array>
using std::array;

namespace bf
{
    /*!
        \brief
     */
    template <typename T=uint32_t, size_t n=30000>
    class Memory
    {
        public:

        Memory() : memory_(), iterator_(memory_.begin()) { };

        virtual ~Memory() = default;

        /*!
            Increases the value in the cell pointed by the iterator
            \param[in] offset The number by which to increase the current cell value 
         */
        inline void IncrementValue(T offset) { *this->iterator_ += offset; };
        /*!
            Decreases the value in the cell pointed by the iterator
            \param[in] offset The number by which to decrease the current cell value
         */
        inline void DecrementValue(T offset) { *this->iterator_ -= offset; };

        /*!
            Moves the cell pointer to the right in the array
            \param[in] offset The number to shift the cell pointer
         */
        inline void MoveForward(ssize_t offset) { this->iterator_ += offset; };
        /*!
            Moves the cell pointer to the left in the array
            \param[in] offset The number to shift the cell pointer
         */
        inline void MoveBackward(ssize_t offset) { this->iterator_ -= offset; };

        /*!
            Reads the value from the current active cell
            \returns The value stored in the cell pointed by the iterator
         */
        inline T ReadValue() const { return *this->iterator_; }

        private:

        /*!
            One-dimensional array representing program storage
            By default every cell must be initialized to zero
         */
        std::array<T, n> memory_;

        /*!
            Movable array iterator to select active cell
            By default points to the first byte of the array
         */
        typename decltype(memory_)::iterator iterator_; 
    };
}

#endif // BFI_MEMORY_MEMORY_H