#include "Backend.h"

void Backend::initialize()
{
    window = Window::initWindow();
}

void Backend::run()
{
    float FirstFrame = 0.0f;
    
    while(!glfwWindowShouldClose(window))
    {
        float CurrentFrame = glfwGetTime();
        float DeltaTime = CurrentFrame - FirstFrame;
        FirstFrame = CurrentFrame;
    }
    glfwTerminate();
}
