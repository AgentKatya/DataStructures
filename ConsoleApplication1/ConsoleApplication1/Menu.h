#pragma once
class Menu
{
public:
    static void MenuRingBufferQueue(RingBufferQueue* queue);
    static void MenuStackQueue(StackQueue* queue);
    static void MenuBuffer(RingBuffer* buffer);
    static void MenuStack(Stack* stack);
    static int InputInt(const char* message, const char* regex);
    static int InputPositiveInt(const char* message);
    static int InputInt(const char* message);
};


