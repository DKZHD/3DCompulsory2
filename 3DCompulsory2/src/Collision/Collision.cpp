#include "Collision.h"
#include "../Backend/Backend.h"
#include <iostream>
#include "../Mesh/Mesh.h"
#include "glm/gtx/dual_quaternion.hpp"
#include "glm/gtx/matrix_interpolation.hpp"
#include "glm/gtx/quaternion.hpp"

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
                 std::cout << "Cube is player\n";
             }
        }
        else
        {
            originalCameraPos = Backend::camera.cameraPos;
            if(bIsCameraLock)
            {
                bIsCameraLock = false;
                Backend::camera.CameraLock = false;
            }
            
            Backend::camera.cameraFront = glm::vec3(-1.f, -0.1f, -1.f);
            Backend::camera.CameraLock = true;
            bIsCameraLock = true;
           
        }
       if (other.cube != nullptr)
       {
           if (other.cube->bIsPlayer)
           {
               other.cube->bCanInteract = true;
               if(cube)
                other.cube->OverlappedCube = cube;
               std::cout << "Other is player\n";
           }
       }
        else
        {
            std::cout << "Other is not player\n";
        }
         return true;
    }
    return false;
}

glm::vec3 Collision::lerp(glm::vec3 a, glm::vec3 b, float f)
{
    // Backend::camera.cameraPos = glm::eulerAngles(glm::lerp(glm::toQuat(glm::translate(glm::mat4(1.f),
    //  a)),glm::toQuat(glm::translate(glm::mat4(1.f),b)), f));
    // glm::mat4 shit = glm::interpolate(glm::translate(glm::mat4(1.f), a), glm::translate(glm::mat4(1.f), b), 1.f);
    // glm::vec4 shit2 = glm::vec4(1.f);
    // glm::vec4 shit3 = shit*shit2;
    // std::cout << shit3.x << " " << shit3.y << "  "<< shit3.z << "  "<<  shit3.w << std::endl;
    // Backend::camera.cameraPos = glm::vec3(shit3.x,shit3.y,shit3.z);
    auto shit = [f,a,b](glm::vec3 lerpLocation)
    {
        Backend::camera.cameraPos = (1.f-f)*a+f*b;
    };
    
    return Backend::camera.cameraPos;
}
