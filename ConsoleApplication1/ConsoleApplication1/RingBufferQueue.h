#pragma once
#include <ostream>
#include "RingBuffer.h"
using namespace std;

class RingBufferQueue
{
private:
    struct Node
    {
        int Value;
        Node* Next;
    };
    Node* Last;
    int Size;

public:
    RingBufferQueue();
    ~RingBufferQueue();
    void Enqueue(int value);
    int Dequeue();
    int GetSize() const;
    bool IsEmpty() const;
    void Clear();
    Node* GetLast() const;
    friend ostream& operator<<(ostream& os, const RingBufferQueue& queue);
};


