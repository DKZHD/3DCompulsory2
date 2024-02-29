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
    
    virtual void initialize();
    void run();
    virtual void Update(float deltaTime);
    
};
