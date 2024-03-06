#include "Collision.h"
#include "../Backend/Backend.h"
#include <iostream>
#include "../Mesh/Mesh.h"
#include "glm/ext/scalar_common.hpp"
#include "glm/gtx/dual_quaternion.hpp"
#include "glm/gtx/matrix_interpolation.hpp"
#include "glm/gtx/quaternion.hpp"

Collision::Collision(glm::vec3 position, glm::vec3 scale, glm::vec3 offset, ECollisionType collision_type, Cube* realCube) : scale(scale), offset(offset), collisionType(collision_type)
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

    if(other.min.x < max.x && other.max.x > min.x &&
        other.min.y < max.y && other.max.y > min.y &&
        max.z <= other.min.z && min.z >= other.max.z)
    {
        if(cube == nullptr && other.cube == nullptr)
            return true;

        if(cube != nullptr)
        {
             if (cube->bIsPlayer)
             {
                 cube->bCanInteract = true;
                 if(other.cube)
                    cube->OverlappedCube = other.cube;
             }
        }
        else
        {
            if (HasOverlapped == true)
            {
                timer += Backend::DeltaTime*0.5f;
                timer = glm::clamp(timer, 0.f, 1.01f);
                lerp(Backend::camera.cameraPos, glm::vec3(14.8, 2.5, -5.2), timer);
            }
            else
            {
                HasOverlapped = true;
                timer = 0.f;
                Backend::camera.cameraFront = glm::vec3(-1.f, -0.2f, -1.f);
                Backend::camera.CameraLock = true;
                bIsCameraLock = true;
            }
        }
       if (other.cube != nullptr)
       {
           if (other.cube->bIsPlayer)
           {
               other.cube->bCanInteract = true;
               if(cube)
                other.cube->OverlappedCube = cube;
           }
       }
        else
        {

        }
         return true;
    }

    return false;
}

glm::vec3 Collision::lerp(glm::vec3 a, glm::vec3 b, float f)
{
    if (f >= 1.f)
    {
        return Backend::camera.cameraPos;
    }

    Backend::camera.cameraPos = glm::mix(Backend::camera.cameraPos, glm::vec3(14.8f, 2.5f, -5.2f), f);
    return Backend::camera.cameraPos;
}
