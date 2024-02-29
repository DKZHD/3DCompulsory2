#include "Collision.h"
#include <iostream>
#include "../Mesh/Mesh.h"

Collision::Collision(glm::vec3 position, glm::vec3 scale, Cube* realCube)
{
    min = position - scale;
    max = position + scale;

    cube = realCube;
}


void Collision::checkWorldCollision()
{
    
}

void Collision::checkCollision(Collision& cube1)
{
    if(cube1.min.x < max.x && cube1.max.x > min.x &&
        cube1.min.y < max.y && cube1.max.y > min.y &&
        cube1.min.z < max.z && cube1.max.z > min.z)
    {
        std::cout << "Collision" << std::endl;
        if(cube.bIsPlayer == true || cube1.cube.bIsPlayer == true)
        {
            std::cout << "Player Collision" << std::endl;
        }
    }
}
