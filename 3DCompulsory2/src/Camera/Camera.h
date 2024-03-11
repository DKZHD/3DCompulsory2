#pragma once
#include "glm/fwd.hpp"
#include "glm/vec3.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "../Shaders/Shader.h"

class Camera
{

public:

    glm::vec3 cameraFront = glm::vec3 (0.0f, 0.0f,-1.0f);
    glm::vec3 cameraUp = glm::vec3 (0.0f, 1.0f, 0.0f);
    glm::vec3 PlayerPos = glm::vec3(0.375f, 1.15f, -0.375f);
    glm::vec3 cameraPos = glm::vec3(PlayerPos.x, PlayerPos.y, PlayerPos.z) + cameraFront * -3.f;
    float cameraSpeed = 5.f;

    int viewLoc;
    int projectionLoc;
    bool CameraLock = false;
    
    void initCamera();

    glm::mat4 view;
    glm::mat4 projection;

    // Get camera view
    glm::mat4 getView();
    // Get camera projection
    glm::mat4 getProjection(float width, float height);
    // Sets player position
    void setPlayerPos(glm::vec3 position);
    // Offsets camera a set distance around the center of the player
    glm::vec3 OrbitCamera(glm::vec3 direction);

    void updatePos(glm::vec3 newpos);
};
