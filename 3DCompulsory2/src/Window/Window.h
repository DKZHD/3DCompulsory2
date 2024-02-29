#pragma once
#include "GLFW/glfw3.h"
#include <iostream>

class Window
{
public:

    static float height;
    static float width;
    
    static GLFWwindow* initWindow();

};
