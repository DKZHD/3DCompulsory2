#include "Backend.h"



void Backend::initialize()
{
    window = Window::initWindow();
    camera.initCamera();
}

void Backend::run()
{
    float FirstFrame = 0.0f;
    
    while(!glfwWindowShouldClose(window))
    {
        float CurrentFrame = glfwGetTime();
        float DeltaTime = CurrentFrame - FirstFrame;
        FirstFrame = CurrentFrame;

        glUniformMatrix4fv(camera.viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getView()));
        glUniformMatrix4fv(camera.projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.getProjection(800, 600)));
    }
    glfwTerminate();
}
