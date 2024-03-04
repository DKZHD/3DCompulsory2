#include "Collision.h"
#include <iostream>
#include "../Mesh/Mesh.h"

Collision::Collision(glm::vec3 position, glm::vec3 scale, Cube* realCube) : scale(scale)
{
    min = position;
    max = position + scale;
    max.z = position.z - scale.z;

    cube = realCube;
}

void Collision::UpdatePosition(glm::vec3 position)
{
    min = position;
    max = position + scale;
    max.z = position.z - scale.z;
}


void Collision::checkWorldCollision()
{
    
}

bool Collision::checkCollision(Collision& other)
{
    PrintBool(other.min.x < max.x && other.max.x > min.x);
    PrintBool(other.min.y < max.y && other.max.y > min.y);
    PrintBool(max.z <= other.min.z && min.z >= other.max.z);

    if(other.min.x < max.x && other.max.x > min.x &&
        other.min.y < max.y && other.max.y > min.y &&
        max.z <= other.min.z && min.z >= other.max.z)
    {
        std::cout << "Collision" << std::endl;
        return true;
        // if(cube.bIsPlayer == true || other.cube.bIsPlayer == true)
        // {
        //     std::cout << "Player Collision" << std::endl;
        // }
    }
    return false;
    //std::cout << "Cube 1 min: " << min.y << ",  max: " << max.y << "\n";
    //std::cout << "Cube 2 min: " << other.min.y << ",  max: " << other.max.y << "\n";
}
