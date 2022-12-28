#include <iostream>
#include <regex>
#include "Stack.h"
#include "StackQueue.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h"
#include "Menu.h"
using namespace std;

int Menu::InputInt(const char* message)
{
    return InputInt(message, "-?[0-9]+");
}

int Menu::InputPositiveInt(const char* message)
{
    return InputInt(message, "[0-9]+");
}

int Menu::InputInt(const char* message, const char* regex)
{
    string input;
    while (true)
    {
        cout << message;
        cin >> input;
        if (regex_match(input, std::regex(regex)))
        {
            return stoi(input);
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}

void Menu::MenuRingBufferQueue(RingBufferQueue* queue)
{
    while (true)
    {
        cout << "==== Ring buffer queue menu ====\n"
                "1. Enqueue\n"
                "2. Dequeue\n"
                "3. Get size\n"
                "4. Is empty\n"
                "5. Print\n"
                "6. Back" << endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
        case 1:
        {
            int value = InputInt("Enter Value: ");
            queue->Enqueue(value);
            break;
        }
        case 2:
        {
            int value = queue->Dequeue();
            if (value == 0)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Dequeued Value: " << value << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Size: " << queue->GetSize() << endl;
            break;
        }
        case 4:
        {
            cout << "Is empty: " << (queue->IsEmpty() ? "true" : "false") << endl;
            break;
        }
        case 5:
        {
            cout << "=== Print ===" << endl;
            cout << *queue << endl;
            break;
        }
        case 6:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}

void Menu::MenuStackQueue(StackQueue* queue)
{
    while (true)
    {
        cout << "==== Stack queue menu ====\n"
                "1. Enqueue\n"
                "2. Dequeue\n"
                "3. Get size\n"
                "4. Print\n"
                "5. Exit" << endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
        case 1:
        {
            int value = InputInt("Enter Value: ");
            queue->Enqueue(value);
            break;
        }
        case 2:
        {
            int value = queue->Dequeue();
            if (value == 0)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Dequeued Value: " << value << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Size: " << queue->GetSize() << endl;
            break;
        }
        case 4:
        {
            cout << "=== Print ===" << endl;
            cout << *queue << endl;
            break;
        }
        case 5:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}

void Menu::MenuBuffer(RingBuffer* buffer)
{
    while (true)
    {
        cout << "==== Buffer menu ====\n"
                "1. Resize buffer\n"
                "2. Add element\n"
                "3. Get element\n"
                "4. Get size\n"
                "5. Print\n"
                "6. Exit" << endl;

        int choice = InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
        case 1:
        {
            int size = InputPositiveInt("Enter new size: ");
            if (size < buffer->GetSize())
            {
                cout << "New size is less than current size" << endl;
                break;
            }
            buffer->Resize(size);
            break;
        }
        case 2:
        {
            char* value = new char[256];
            cout << "Enter Value: ";
            cin >> value;
            buffer->Add(value);
            break;
        }
        case 3:
        {
            char* get = buffer->Get();
            if (get == nullptr)
            {
                cout << "Buffer is empty" << endl;
            }
            else
            {
                cout << "Get Value: " << get << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Size: " << buffer->GetSize() << endl;
            break;
        }
        case 5:
        {
            cout << "=== Print ===" << endl;
            if (buffer->GetCount() == 0)
            {
                cout << "Buffer is empty" << endl;
            }
            else
            {
                cout << *buffer << endl;
            }
            break;
        }
        case 6:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}

void Menu::MenuStack(Stack* stack)
{
    while (true)
    {
        cout << "==== Stack menu ===="
                "1. Push\n"
                "2. Pop\n"
                "3. Peek\n"
                "4. Clear\n"
                "5. Print\n"
                "6. Back" << endl;

        int choice = InputInt("Enter your choice: ");
        switch (choice)
        {
        case 1:
        {
            int value = InputInt("Enter Value: ");
            stack->Push(value);
            break;
        }
        case 2:
        {
            int value = stack->Pop();
            if (value == 0)
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Popped Value: " << value << endl;
            }
            break;
        }
        case 3:
        {
            int value = stack->Peek();
            if (value == 0)
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Peeked Value: " << value << endl;
            }
            break;
        }
        case 4:
        {
            stack->Clear();
            break;
        }
        case 5:
        {
            cout << "==== Print stack ====" << endl;
            if (stack->GetSize() == 0)
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << *stack << endl;
            }
            break;
        }
        case 6:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}