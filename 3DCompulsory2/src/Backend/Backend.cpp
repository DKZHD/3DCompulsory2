#include "Backend.h"

#include "../InputEvents/Input.h"
#include "../Window/Window.h"

float Backend::DeltaTime = 0.f;
Camera Backend::camera = Camera();
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
        const float CurrentFrame = glfwGetTime();
    	DeltaTime = CurrentFrame - FirstFrame;
        FirstFrame = CurrentFrame;


        KeyBoardInput::processInput(window);
        glUniformMatrix4fv(camera.viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getView()));
        glUniformMatrix4fv(camera.projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.getProjection(800, 600)));
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}
