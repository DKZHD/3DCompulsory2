#include "Input.h"
#include "../Backend/Backend.h"
#include "../Camera/Camera.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/ext/quaternion_geometric.hpp"

void Input::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void KeyBoardInput::processInput(GLFWwindow* window)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
	if(glfwGetKey(window, GLFW_KEY_W)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.z -= 3.f * Backend::DeltaTime;
	}
	if(glfwGetKey(window, GLFW_KEY_S)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.z += 3.f * Backend::DeltaTime;
	}
	if(glfwGetKey(window, GLFW_KEY_A)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.x -= 3.f * Backend::DeltaTime;
	}
	if(glfwGetKey(window, GLFW_KEY_D)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.x += 3.f * Backend::DeltaTime;
	}
}

namespace MouseInput
{
	bool firstMouse = true;
	double lastX = 0.f;
	double lastY = 0.f;
	float yaw = -90.f;
	float pitch = 0.f;
	float fov = 70.f;
}


void MouseInput::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;
	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;
	yaw += xoffset;
	pitch += yoffset;
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	Backend::camera.cameraFront = glm::normalize(direction);
}
