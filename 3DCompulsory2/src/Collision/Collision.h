#pragma once
#include <glm/vec3.hpp>
#includ

class Cube;

class Collision
{
public:
    glm::vec3 min;
    glm::vec3 max;

    Cube* cube;
    
    Collision(glm::vec3 position, glm::vec3 scale, Cube* realCube);
    void checkWorldCollision();
    void checkCollision(Collision& cube1);
};
