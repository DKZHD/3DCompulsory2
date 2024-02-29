#pragma once
#include "GLFW/glfw3.h"
#include <iostream>

class Window
{
public:

    float height = 600;
    float width = 800;
    
    static GLFWwindow* initWindow();

};
