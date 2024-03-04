#pragma once
#include "../Mesh/Mesh.h"

class NPC : Mesh
{
public:
    bool bPathCompleted = false;

    std::vector<glm::vec3> Points;
    std::vector<glm::vec3> Path;

    int i = 0;
    
    void initNPC();

    glm::vec4 interpolation(std::vector<glm::vec3> points);
    
    float GetZ(glm::vec4 solution, float x);
    
    void GetPointsInFunction(float step, std::vector<glm::vec3>& vertices, std::vector<glm::vec3> points);

    void updatePos(Cube& cube);
        glm::vec3 getNextPos(float t);
        void calculatePath();
};
