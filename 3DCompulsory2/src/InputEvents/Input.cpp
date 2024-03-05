#include "Input.h"

#include <iostream>

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

void KeyBoardInput::processInput(GLFWwindow* window, Cube* player)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
	if(glfwGetKey(window, GLFW_KEY_W)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.x += 5.f * Backend::camera.cameraFront.x * Backend::DeltaTime;
		Backend::camera.cameraPos.z += 5.f * Backend::camera.cameraFront.z * Backend::DeltaTime;
		player->GetPosition() += 5.f * Backend::camera.cameraFront * Backend::DeltaTime;
		Backend::camera.setPlayerPos(player->GetPosition());
	}
	if(glfwGetKey(window, GLFW_KEY_S)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.x -= 5.f * Backend::camera.cameraFront.x * Backend::DeltaTime;
		Backend::camera.cameraPos.z -= 5.f * Backend::camera.cameraFront.z * Backend::DeltaTime;
		player->GetPosition() -= 5.f * Backend::camera.cameraFront * Backend::DeltaTime;
		Backend::camera.setPlayerPos(player->GetPosition());
	}
	if(glfwGetKey(window, GLFW_KEY_A)==GLFW_PRESS)
	{
		Backend::camera.cameraPos -= (5.f * glm::normalize(glm::cross(Backend::camera.cameraFront, Backend::camera.cameraUp))) * Backend::DeltaTime;
		player->GetPosition() -= (5.f * glm::normalize(glm::cross(Backend::camera.cameraFront, Backend::camera.cameraUp))) * Backend::DeltaTime;
		Backend::camera.setPlayerPos(player->GetPosition());
	}
	if(glfwGetKey(window, GLFW_KEY_D)==GLFW_PRESS)
	{
		Backend::camera.cameraPos += (5.f * glm::normalize(glm::cross(Backend::camera.cameraFront, Backend::camera.cameraUp))) * Backend::DeltaTime;
		player->GetPosition() += (5.f * glm::normalize(glm::cross(Backend::camera.cameraFront, Backend::camera.cameraUp))) * Backend::DeltaTime;
		Backend::camera.setPlayerPos(player->GetPosition());
	}
	if(glfwGetKey(window, GLFW_KEY_SPACE)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.y += 5.f * Backend::DeltaTime;
	}
	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS)
	{
		Backend::camera.cameraPos.y -= 5.f * Backend::DeltaTime;
	}
	if(glfwGetKey(window,GLFW_KEY_E)==GLFW_PRESS)
	{
		if(player->bCanInteract == true && player->OverlappedCube->bIsPickup)
		{
			std::cout << "interacted\n";
			player->OverlappedCube->bShouldRender = false;
			player->OverlappedCube->bIsPickup = false;
		}
	}
	if(glfwGetKey(window,GLFW_KEY_L)==GLFW_PRESS)
	{
		Backend::camera.cameraPos = glm::vec3(3.f, 10.f, 2);
	}
}

namespace MouseInput
{
	bool firstMouse = true;
	double lastX = 0.f;
	double lastY = 0.f;
	float yaw = -90.f;
	float pitch = 0.f;
	float fov = 45.f;
}


void MouseInput::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(!Backend::camera.CameraLock)
	{
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}
		auto xoffset = static_cast<float>(xpos - lastX);
		auto yoffset = static_cast<float>(lastY - ypos);
		lastX = xpos;
		lastY = ypos;
		const float sensitivity = 0.05f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		yaw += xoffset;
		pitch += yoffset;
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
		glm::vec3 direction;
		Backend::camera.cameraFront;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = 0; /*sin(glm::radians(pitch));*/
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		Backend::camera.OrbitCamera(direction);
	}

}
