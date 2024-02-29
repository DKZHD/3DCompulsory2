#pragma once
#include "../Window/Window.h"
#include "GLFW/glfw3.h"

class Backend
{
public:
    Window *WindowInit;
    
    void initialize(Window* initPtr);
    void run();
    
};
