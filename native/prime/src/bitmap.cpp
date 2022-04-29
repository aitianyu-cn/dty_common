#include "../bitmap.hpp"

#define _dty_bitmap_internal_get_bit_op_num_by_offset(bitOffset) (0b01 << (bitOffset))

dty::collection::Bitmap::Bitmap(int64 bitsCount)
    : dty::TianyuObject(),
    _ArraySize(0),
    _Map(::null),
    _BitsCount(bitsCount),
    Count(_BitsCount)
{
    if (0 >= bitsCount)
        throw dty::except::ArgumentOutOfRangeException();

    this->_ArraySize = bitsCount >> 3;
    if (0 != (bitsCount & 0b111))
        this->_ArraySize += 1;

    this->_Map = new byte[this->_ArraySize];
}

dty::collection::Bitmap::Bitmap(int64 bitsCount, bool fillState)
    : dty::TianyuObject(),
    _ArraySize(0),
    _Map(::null),
    _BitsCount(bitsCount),
    Count(_BitsCount)
{
    if (0 >= bitsCount)
        throw dty::except::ArgumentOutOfRangeException();

    this->_ArraySize = bitsCount >> 3;
    if (0 != (bitsCount & 0b111))
        this->_ArraySize += 1;

    this->_Map = new byte[this->_ArraySize];

    byte fillValue = fillState ? 0xFF : 0x00;
    for (int64 i = 0; i < this->_ArraySize; ++i)
        this->_Map[i] = fillValue;
}

dty::collection::Bitmap::Bitmap(byte* bits, int32 length, int32 bitsCount = -1, bool copyBits)
    : dty::TianyuObject(),
    _ArraySize(length),
    _Map(bits),
    _BitsCount(bitsCount),
    Count(_BitsCount)
{
    if (::null == bits)
        throw dty::except::ArgumentNullException();

    if (0 >= length)
        throw dty::except::ArgumentOutOfRangeException();

    if (-1 != bitsCount)
    {
        int32 reqLen = (bitsCount >> 3) + (0 == (bitsCount & 0b111) ? 0 : 1);
        if (reqLen > length)
            throw dty::except::ArgumentOutOfRangeException();
    }

    if (copyBits)
    {
        this->_Map = new byte[this->_ArraySize];
        for (int32 i = 0; i < this->_ArraySize; ++i)
            this->_Map[i] = bits[i];
    }
}

dty::collection::Bitmap::~Bitmap()
{
    if (::null != this->_Map)
        delete [] this->_Map;
}

void dty::collection::Bitmap::Fill(bool state)
{
    if (::null == this->_Map)
        return;

    byte fillValue = state ? 0xFF : 0x00;
    for (int64 i = 0; i < this->_ArraySize; ++i)
        this->_Map[i] = fillValue;
}

void dty::collection::Bitmap::RollOver(int64 bitIndex)
{
    bool preState = this->Test(bitIndex);
    this->Set(bitIndex, preState);
}

void dty::collection::Bitmap::Set(int64 bitIndex, bool state)
{
    if (0 > bitIndex || bitIndex > this->_BitsCount)
        throw dty::except::ArgumentOutOfRangeException();

    int64 mapIndex = bitIndex >> 3;
    int32 bitOffset = _dty_bitmap_internal_get_bit_op_num_by_offset(bitIndex & 0b111);

    if (state)
        this->_Map[mapIndex] |= bitOffset;
    else
        this->_Map[mapIndex] &= ~bitOffset;
}

bool dty::collection::Bitmap::Test(int64 bitIndex)
{
    if (0 > bitIndex || bitIndex > this->_BitsCount)
        throw dty::except::ArgumentOutOfRangeException();

    int64 mapIndex = bitIndex >> 3;
    int32 bitOffset = _dty_bitmap_internal_get_bit_op_num_by_offset(bitIndex & 0b111);

    return 0 != ((this->_Map[mapIndex]) & bitOffset);
}

byte* dty::collection::Bitmap::ToBytes(int64& arrayLength, bool copy = false)
{
    arrayLength = this->_ArraySize;

    if (!copy)
        return this->_Map;

    byte* copyBits = new byte[this->_ArraySize];
    for (int32 i = 0; i < arrayLength; ++i)
        copyBits[i] = this->_Map[i];

    return copyBits;
}

::string dty::collection::Bitmap::ToString() noexcept
{
    return dty::_dty_native_cpp_default_to_string(__PTR_TO_REF__ this);
}

uint64 dty::collection::Bitmap::GetTypeId()
{
    return dty::GetType(__PTR_TO_REF__ this).Id();
}

uint64 dty::collection::Bitmap::GetHashCode()
{
    return (uint64)(this);
}
