#include <cstddef>
#include <cstdint>
#ifndef A1B1D4B6_6078_4736_9D9C_7A4DCF6A0AC3
#define A1B1D4B6_6078_4736_9D9C_7A4DCF6A0AC3


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


    private:
        uint8_t* array;
        size_t byteQty;
        size_t bitQty;
};



#endif /* A1B1D4B6_6078_4736_9D9C_7A4DCF6A0AC3 */
