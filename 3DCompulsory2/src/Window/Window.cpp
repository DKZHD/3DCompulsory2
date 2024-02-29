#include "../Shaders/Shader.h"
#include "Window.h"
#include "../InputEvents/Input.h"

float Window::width = 800.f;
float Window::height = 600.f;
GLFWwindow* Window::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window;
    window = glfwCreateWindow((int)width,(int)height,"Compulsory 2",NULL,NULL);
    if(window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glViewport(0,0,width,height);
    glEnable(GL_DEPTH_TEST);
    Shader::CreateProgram();
    glfwSetFramebufferSizeCallback(window,Input::framebuffer_size_callback);
    glfwSetCursorPosCallback(window, MouseInput::mouse_callback);
    return window;
}

