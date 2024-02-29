#include "Backend.h"

void Backend::initialize(Window* initPtr)
{
    glfwInit();
    WindowInit = initPtr;
    WindowInit->initWindow();
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
    glfwTerminate();
}
