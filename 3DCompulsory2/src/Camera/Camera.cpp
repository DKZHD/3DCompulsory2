#include "Camera.h"

#include "glm/gtx/matrix_transform_2d.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/rotate_vector.hpp"

void Camera::initCamera()
{
    viewLoc = glGetUniformLocation(Shader::Program, "view");
    projectionLoc = glGetUniformLocation(Shader::Program, "projection");
}

glm::mat4 Camera::getView()
{
    glm::mat4 view = glm::mat4(1.f);
    //cameraPos = glm::vec3(PlayerPos.x, cameraPos.y, PlayerPos.z+3.f);
    view = glm::lookAt(cameraPos, cameraPos+cameraFront, cameraUp);
    return view;
}

glm::mat4 Camera::getProjection(float width, float height)
{
    glm::mat4 proj = glm::mat4(1.f);
    proj = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    return proj;
}

void Camera::setPlayerPos(glm::vec3 position)
{
    PlayerPos = glm::vec3(PlayerPos.x + position.x, 0.65f, PlayerPos.z + position.z);
}

glm::vec3 Camera::OrbitCamera(glm::vec3 direction)
{
    cameraPos.x = PlayerPos.x;
    cameraPos.z = PlayerPos.z;
    cameraFront = glm::normalize(direction);
    cameraPos = PlayerPos - cameraFront.x * 3.f;
    cameraPos.y = 2.f;
    return cameraPos;
}

void Camera::updatePos(glm::vec3 newpos)
{
    cameraPos += newpos;
    cameraFront += newpos;
}
