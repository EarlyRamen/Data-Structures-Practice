#ifndef CA5F338B_E776_47A4_865F_42F690AB2A22
#define CA5F338B_E776_47A4_865F_42F690AB2A22
#include <cstddef>
#include <cstdint>

class BitArray{
    public:
        BitArray(size_t);
        BitArray(size_t,bool);
        void setBit(size_t);
        void setBit(size_t, bool);
        void unset(size_t);
        bool getBit(size_t);
        void clear(bool);
        void clear(); //unset all bit
        const uint8_t* getArray();
        size_t getByteQty();

    private:
        void setBit(size_t);
        void unsetBit(size_t);

        uint8_t* array;
        size_t byteQty;
        size_t bitQty;
};


#endif /* CA5F338B_E776_47A4_865F_42F690AB2A22 */
