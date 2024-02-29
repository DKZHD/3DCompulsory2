#pragma once

class Camera;
struct GLFWwindow;

class Input
{
public:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

class KeyBoardInput
{

public:
	void processInput(GLFWwindow* window, Camera& camera);
};

namespace MouseInput
{
	extern bool firstMouse;
	extern double lastX;
	extern double lastY;

	extern float yaw;
	extern float pitch;

	extern float fov;

	extern Camera* camera;
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
}