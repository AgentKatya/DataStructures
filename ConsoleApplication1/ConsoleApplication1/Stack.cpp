#include "Stack.h"
using namespace std;

Node* Node::GetNext() const
{
    return Next;
}

void Node::SetNext(Node* next)
{
    Next = next;
}

Node::Node(int value)
{
    this->Data = value;
}

int Node::GetData() const
{
    return Data;
}

Node* Stack::Push(int value)
{
    auto* node = new Node(value);
    node->SetNext(Last);
    Last = node;
    Size++;
    return node;
}

int Stack::Pop()
{
    if (Size == 0)
    {
        return 0;
    }
    auto* node = Last;
    Last = Last->GetNext();
    Size--;
    int data = node->GetData();
    delete node;
    return data;
}

int Stack::Peek()
{
    if (Size == 0)
    {
        return 0;
    }
    return Last->GetData();
}

void Stack::Clear()
{
    while (Size > 0)
    {
        Pop();
    }
}

int Stack::GetSize() const
{
    return Size;
}

Node* Stack::GetLast() const
{
    return Last;
}

ostream& operator<<(ostream& os, const Stack& stack)
{
    os << "=== Stack ===" << endl;
    os << "Size: " << stack.GetSize() << endl;
    os << "Last: " << stack.GetLast()->GetData() << endl;
    os << "Elements: " << std::endl;
    os << "[";
    auto* node = stack.Last;
    while (node != nullptr)
    {
        os << node->GetData();
        node = node->GetNext();
        if (node != nullptr)
        {
            os << ", ";
        }
    }
    os << "]" << endl;
    return os;
}
