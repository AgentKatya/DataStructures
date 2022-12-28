#pragma once
#include <ostream>
#include "Stack.h"
using namespace std;

class StackQueue
{
private:
    Stack* StackIn;
    Stack* StackOut;
    int Size;
public:
    StackQueue();
    void Enqueue(int value);
    int Dequeue();
    void Clear();
    int GetSize() const;
    Stack* GetStackIn() const;
    Stack* GetStackOut() const;
    friend ostream& operator<<(ostream& os, const StackQueue& queue);
};


