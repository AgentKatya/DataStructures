#include <iostream>
#include "Stack.h"
#include "RingBuffer.h"
#include "StackQueue.h"
#include "RingBufferQueue.h"
#include "Menu.h"
using namespace std;

int main()
{
    auto* stack = new Stack();
    auto* stackQueue = new StackQueue();
    auto* ringBufferQueue = new RingBufferQueue();

    while (true)
    {
        cout << "1. Stack\n" 
                "2. RingBuffer\n"
                "3. StackQueue\n"
                "4. RingBufferQueue\n"
                "5. Exit\n" << endl;

        int choice = Menu::InputPositiveInt("Enter your choice: ");
        switch (choice)
        {
        case 1:
        {
            Menu::MenuStack(stack);
            break;
        }
        case 2:
        {
            int size = Menu::InputPositiveInt("Enter buffer size: ");
            auto* buffer = new RingBuffer(size);
            Menu::MenuBuffer(buffer);
            break;
        }
        case 3:
        {
            Menu::MenuStackQueue(stackQueue);
            break;
        }
        case 4:
        {
            Menu::MenuRingBufferQueue(ringBufferQueue);
            break;
        }
        case 5:
        {
            return false;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}
