#pragma once
#include "../Window/Window.h"
#include "GLFW/glfw3.h"

class Backend
{
public:
    GLFWwindow *window;
    
    void initialize();
    void run();
    
};
