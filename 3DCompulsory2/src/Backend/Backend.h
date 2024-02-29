#pragma once
#include "../Window/Window.h"
#include "../Camera/Camera.h"
#include "glm/gtc/type_ptr.inl"
#include "GLFW/glfw3.h"

class Backend
{
public:
    GLFWwindow *window;
    Camera camera;
    
    void initialize();
    void run();
    
};
