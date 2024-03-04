#include "NPC.h"

#include "../Backend/Backend.h"
#include "glm/gtx/matrix_interpolation.hpp"
#include "glm/gtx/transform.hpp"
#include "../Mesh/Mesh.h"

void NPC::initNPC()
{
    Points.emplace_back(glm::vec3(0,0,0));
    Points.emplace_back(glm::vec3(20,0,12));
    Points.emplace_back(glm::vec3(30,0,20));
    Points.emplace_back(glm::vec3(35,0,17));

    GetPointsInFunction(0.01f, Path, Points);
}

glm::vec4 NPC::interpolation(std::vector<glm::vec3> points)
{
    glm::mat4 A{points[0].x * points[0].x * points[0].x, points[0].x * points[0].x, points[0].x, 1,
            points[1].x * points[1].x * points[1].x, points[1].x * points[1].x, points[1].x, 1,
            points[2].x * points[2].x * points[2].x, points[2].x * points[2].x, points[2].x, 1,
            points[3].x * points[3].x * points[3].x, points[3].x * points[3].x, points[3].x, 1};

    glm::vec4 y{points[0].y, points[1].y, points[2].y, points[3].y};
    
    glm::vec4 solution = glm::inverse(A) * y;
    return solution;
}

float NPC::GetZ(glm::vec4 solution, float x)
{
    float a = solution.x;
    float b = solution.y;
    float c = solution.z;
    float d = solution.w;

    return a*x*x*x + b*x*x + c*x +d;
}

void NPC::GetPointsInFunction(float step, std::vector<glm::vec3>& path, std::vector<glm::vec3> points)
{
    glm::vec4 solution = interpolation(points);
    for (float x = points[0].x; x < points[3].x; x += step)
    {
        float z = GetZ(solution, x);
        float y = 0;

        path.emplace_back(x,y,z);
    }
}

void NPC::updatePos(Cube& cube)
{
    if(i>=Path.size())
    {
        bPathCompleted = true;
        i--;
    }
    if(i<=0)
    {
        bPathCompleted = false;
        i++;
    }
  cube.GetPosition() = Path[i];
    if(!bPathCompleted)
    {
       i++;  
    }
    if(bPathCompleted)
    {
        i--;
    }
    
}

