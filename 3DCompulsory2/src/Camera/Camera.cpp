#include "Camera.h"

void Camera::initCamera()
{
    viewLoc = glGetUniformLocation(Shader::Program, "view");
    projectionLoc = glGetUniformLocation(Shader::Program, "projection");
}

glm::mat4 Camera::getView()
{
    return glm::lookAt(cameraPos, cameraFront, cameraUp);
}

glm::mat4 Camera::getProjection(float width, float height)
{
    return glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
}

void Camera::updatePos(glm::vec3 newpos)
{
    cameraPos += newpos;
    cameraFront += newpos;
}
