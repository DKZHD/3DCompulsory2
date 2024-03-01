#include "Camera.h"

void Camera::initCamera()
{
    viewLoc = glGetUniformLocation(Shader::Program, "view");
    projectionLoc = glGetUniformLocation(Shader::Program, "projection");
}

glm::mat4 Camera::getView()
{
    glm::mat4 view = glm::mat4(1.f);
    view = glm::lookAt(cameraPos, cameraPos+cameraFront, cameraUp);
    return view;
}

glm::mat4 Camera::getProjection(float width, float height)
{
    glm::mat4 proj = glm::mat4(1.f);
    proj = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    return proj;
}

void Camera::updatePos(glm::vec3 newpos)
{
    cameraPos += newpos;
    cameraFront += newpos;
}
