#pragma once
#include "GLFW/glfw3.h"
#include <iostream>
#include "glad/glad.h"

class Window
{
public:
    GLFWwindow* window;

    float height;
    float width;
    
    void initWindow();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
