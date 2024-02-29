#include "Backend.h"

#include <immintrin.h>

#include "GLFW/glfw3.h"

void Backend::initialize(Window* initPtr)
{
    WindowInit = initPtr;
}

void Backend::run()
{
    float FirstFrame = 0.0f;
    glEnable(GL_DEPTH_TEST);
    
    while(!glfwWindowShouldClose(WindowInit->window))
    {
        float CurrentFrame = glfwGetTime();
        float DeltaTime = CurrentFrame - FirstFrame;
        FirstFrame = CurrentFrame;
    }
}
