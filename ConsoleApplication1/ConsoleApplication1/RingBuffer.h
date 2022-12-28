#pragma once
#include <ostream>
using namespace std;

class RingBuffer
{
private:
    char** Buffer;
    int Size;
    int Count;
    int FirstIndex;
    int LastIndex;
public:
    RingBuffer(int size);
    ~RingBuffer();
    void Add(char* value);
    char* Get();
    int GetSize() const;
    int GetFreeSize() const;
    int GetCount() const;
    void Resize(int size);
    char** GetBuffer() const;
    int GetFirstIndex() const;
    int GetLastIndex() const;
    friend ostream& operator<<(ostream& os, const RingBuffer& buffer);
};


