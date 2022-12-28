#include <iostream>
#include "RingBuffer.h"
using namespace std;

RingBuffer::RingBuffer(int size)
{
    FirstIndex = 0;
    LastIndex = 0;
    Count = 0;
    Size = size;
    Buffer = new char* [Size];
    for (int i = 0; i < Size; i++)
    {
        Buffer[i] = nullptr;
    }
}

void RingBuffer::Add(char* value)
{
    if (Count == Size)
    {
        Buffer[FirstIndex] = value;
        FirstIndex = (FirstIndex + 1) % Size;
        LastIndex = (LastIndex + 1) % Size;
        return;
    }
    Buffer[LastIndex] = value;
    LastIndex = (LastIndex + 1) % Size;
    Count++;
}

char* RingBuffer::Get()
{
    if (Count == 0)
    {
        return nullptr;
    }
    char* value = Buffer[FirstIndex];
    Buffer[FirstIndex] = nullptr;
    FirstIndex = (FirstIndex + 1) % Size;
    Count--;
    return value;
}

int RingBuffer::GetSize() const
{
    return Size;
}

int RingBuffer::GetFreeSize() const
{
    return Size - Count;
}

int RingBuffer::GetCount() const
{
    return Count;
}

void RingBuffer::Resize(int size)
{
    if (size < Count)
    {
        return;
    }
    char** newBuffer = new char* [size];
    for (int i = 0; i < size; i++)
    {
        newBuffer[i] = nullptr;
    }
    for (int i = 0; i < Count; i++)
    {
        newBuffer[i] = Buffer[(FirstIndex + i) % Size];
    }
    delete[] Buffer;
    Buffer = newBuffer;
    Size = size;
    FirstIndex = 0;
    LastIndex = Count;
}

RingBuffer::~RingBuffer()
{
    delete[] Buffer;
}

char** RingBuffer::GetBuffer() const
{
    return Buffer;
}

int RingBuffer::GetFirstIndex() const
{
    return FirstIndex;
}

int RingBuffer::GetLastIndex() const
{
    return LastIndex;
}

ostream& operator<<(ostream& os, const RingBuffer& buffer)
{
    os << "=== RingBuffer ===" << endl;
    os << "Size: " << buffer.GetSize() << endl;
    os << "Count: " << buffer.GetCount() << endl;
    os << "Free size: " << buffer.GetFreeSize() << endl;
    os << "First index: " << buffer.GetFirstIndex() << endl;
    os << "Last index: " << buffer.GetLastIndex() << endl;
    os << "Buffer: " << endl;
    os << "[";
    for (int i = 0; i < buffer.GetSize(); i++)
    {
        if (buffer.GetBuffer()[i] == nullptr)
        {
            os << "null";
        }
        else
        {
            os << buffer.GetBuffer()[i];
        }
        if (i != buffer.GetSize() - 1)
        {
            os << ", ";
        }
    }
    os << "]" << endl;
    os << endl;
    return os;
}
