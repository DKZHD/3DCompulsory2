#include "Collision.h"
#include <iostream>
#include "../Mesh/Mesh.h"

Collision::Collision(glm::vec3 position, glm::vec3 scale, Cube* realCube)
{
    min = position;
    max = position + scale;
    max.z = position.z - scale.z;

    cube = realCube;
}


void Collision::checkWorldCollision()
{
    
}

void Collision::checkCollision(Collision& other)
{
    if(other.min.x < max.x && other.max.x > min.x &&
        other.min.y < max.y && other.max.y > min.y &&
        other.min.z < max.z && other.max.z > min.z)
    {
        std::cout << "Collision" << std::endl;
        // if(cube.bIsPlayer == true || other.cube.bIsPlayer == true)
        // {
        //     std::cout << "Player Collision" << std::endl;
        // }
    }
}
