#pragma once
#include "../Mesh/Mesh.h"

class NPC : Mesh
{
public:
    glm::mat4 startPosition;
    glm::mat4 endPosition;
    
    void initNPC();
    void updatePos();
    void calculatePath();
};
