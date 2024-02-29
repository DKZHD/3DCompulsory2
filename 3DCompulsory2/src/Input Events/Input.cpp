#include "Input.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void Input::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
