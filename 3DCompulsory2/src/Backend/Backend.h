#pragma once
#include "../Window/Window.h"

class Backend
{
public:
    Window *WindowInit;
    
    void initialize(Window* initPtr);
    void run();
    
};
