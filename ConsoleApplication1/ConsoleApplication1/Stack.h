#pragma once
#include <ostream>
using namespace std;

class Node
{
private:
    int Data;
    Node* Next{};
public:
    int GetData() const;
    Node* GetNext() const;
    void SetNext(Node* next);
    Node(int value);
};
class Stack
{
private:
    Node* Last;
    int Size;

public:
    Node* Push(int value);
    int Pop();
    int Peek();
    void Clear();
    int GetSize() const;
    Node* GetLast() const;
    friend ostream& operator<<(ostream& os, const Stack& stack);
};


