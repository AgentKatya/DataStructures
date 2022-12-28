#include <iostream>
#include "RingBufferQueue.h"
using namespace std;

RingBufferQueue::RingBufferQueue()
{
    Last = nullptr;
    Size = 0;
}

RingBufferQueue::~RingBufferQueue()
{
    Clear();
}

void RingBufferQueue::Enqueue(int value)
{
    auto* node = new Node{ value, nullptr };
    if (Last == nullptr)
    {
        node->Next = node;
    }
    else
    {
        node->Next = Last->Next;
        Last->Next = node;
    }
    Size++;
    Last = node;
}

int RingBufferQueue::Dequeue()
{
    if (Last == nullptr)
    {
        return 0;
    }
    auto* node = Last->Next;
    if (node == Last)
    {
        Last = nullptr;
    }
    else
    {
        Last->Next = node->Next;
    }
    Size--;
    int data = node->Value;
    delete node;
    return data;
}

int RingBufferQueue::GetSize() const
{
    return Size;
}

bool RingBufferQueue::IsEmpty() const
{
    return Last == nullptr;
}

void RingBufferQueue::Clear()
{
    if (Last == nullptr)
    {
        return;
    }
    auto* node = Last->Next;
    while (node != Last)
    {
        auto* next = node->Next;
        delete node;
        node = next;
    }
    delete node;
    Last = nullptr;
}

RingBufferQueue::Node* RingBufferQueue::GetLast() const
{
    return Last;
}

ostream& operator<<(ostream& os, const RingBufferQueue& queue)
{
    os << "=== RingBufferQueue ===" << endl;
    if (queue.GetLast() == nullptr)
    {
        os << "Queue is empty" << endl;
        return os;
    }
    auto* node = queue.GetLast()->Next;
    os << "Size: " << queue.GetSize() << endl;
    os << "First: " << node->Value << endl;
    os << "Last: " << queue.GetLast()->Value << endl;
    os << "Elements: ";
    os << "[";
    do
    {
        os << node->Value;
        node = node->Next;
        if (node != queue.GetLast()->Next)
        {
            os << ", ";
        }
    } while (node != queue.GetLast()->Next);
    os << "]" << endl;
    return os;
}
