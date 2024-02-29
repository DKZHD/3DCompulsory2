#pragma once
#include "GLFW/glfw3.h"
#include <iostream>

class Window
{
public:

    static float height = 600.f;
    static float width = 800.f;
    
    static GLFWwindow* initWindow();

};
