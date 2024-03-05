#pragma once
#include <memory>
#include <glm/vec3.hpp>


#define PrintBool(x) std::cout << ((x) ? "True" : "False") << "\n" 

class Cube;

class Collision
{
public:
    glm::vec3 min;
    glm::vec3 max;
    glm::vec3 scale;

    glm::vec3 originalCameraPos;

    bool bIsCameraLock = false;

    Cube* cube;
    
    Collision(glm::vec3 position, glm::vec3 scale, Cube* realCube);
    void UpdatePosition(glm::vec3 position);
    void checkWorldCollision();
    bool checkCollision(Collision& other);
    glm::vec3 lerp(glm::vec3 a, glm::vec3 b, float f);
};
