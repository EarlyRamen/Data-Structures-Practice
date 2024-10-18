#include "bit_array.h"
#include <stdexcept>

#define ALL_ZERO 0
#define ALL_ONE 0xFF
#define MASK 0b00000001
#define BIT_MASK 0b0111

BitArray::BitArray(size_t bitQty) : BitArray(bitQty, false) {}

BitArray::BitArray(size_t bitQty, bool state){
    bitQty=bitQty;
    byteQty=(bitQty>>3)+1;
    array=new uint8_t[byteQty];
    clear(state);
}

void BitArray::setBit(size_t pos){
    size_t bytePos=(pos>>3);
    size_t bitPos=(pos&BIT_MASK);

    array[bytePos] |= (MASK<<bitPos);

}

void BitArray::setBit(size_t pos, bool state){
    if(pos>=bitQty) throw std::length_error("Pos out of bound");
    state ? setBit(pos) : unset(pos);
}

void BitArray::unset(size_t pos){
    size_t bytePos=(pos>>3);
    size_t bitPos=(pos&BIT_MASK);

    array[bytePos]&=~(MASK<<bitPos);
}

bool BitArray::getBit(size_t pos)
{
    size_t bytePos=(pos>>3);
    size_t bitPos=(pos&BIT_MASK);
    return array[bytePos] & (MASK<<bitPos);
}

void BitArray::clear(bool state){
    for (size_t i = 0; i < byteQty; ++i){
        array[i]=(state)? ALL_ONE : ALL_ZERO;
    }
}

void BitArray::clear() {clear(false);}

const uint8_t* getArray()
{

}

size_t BitArray::getByteQty(){return byteQty;}
