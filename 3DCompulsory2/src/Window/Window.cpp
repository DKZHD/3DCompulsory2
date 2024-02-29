#include "../Shaders/Shader.h"
#include "Window.h"
#include "../Input Events/Input.h"


GLFWwindow* Window::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window;
    window = glfwCreateWindow((int)800,(int)600,"Compulsory 2",NULL,NULL);
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
    glViewport(0,0,800,600);
    glEnable(GL_DEPTH_TEST);
    Shader::CreateProgram();
    glfwSetFramebufferSizeCallback(window,Input::framebuffer_size_callback);
    return window;
}

