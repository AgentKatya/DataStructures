#include <iostream>
#include "StackQueue.h"
#include "Stack.h"
using namespace std;

StackQueue::StackQueue()
{
    StackIn = new Stack();
    StackOut = new Stack();
    Size = 0;
}

void StackQueue::Enqueue(int value)
{
    StackIn->Push(value);
    Size++;
}

int StackQueue::Dequeue()
{
    if (Size == 0)
    {
        return 0;
    }
    if (StackOut->GetSize() == 0)
    {
        while (StackIn->GetSize() > 0)
        {
            StackOut->Push(StackIn->Pop());
        }
    }
    Size--;
    return StackOut->Pop();
}

void StackQueue::Clear()
{
    StackIn->Clear();
    StackOut->Clear();
    Size = 0;
}

int StackQueue::GetSize() const
{
    return Size;
}

Stack* StackQueue::GetStackIn() const
{
    return StackIn;
}

Stack* StackQueue::GetStackOut() const
{
    return StackOut;
}

ostream& operator<<(ostream& os, const StackQueue& queue)
{
    os << "StackIn: " << *queue.GetStackIn() << endl;
    os << "StackOut: " << *queue.GetStackOut() << endl;
    return os;
}
