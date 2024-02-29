#pragma once
#include "../Camera/Camera.h"
#include "glm/gtc/type_ptr.inl"

struct GLFWwindow;

class Backend
{
public:
    GLFWwindow *window;
    static Camera camera;
    static float DeltaTime;
    
    void initialize();
    void run();
    
};
