#include "FrontEnd.h"
#include <iostream>
#include "../Color.h"

void FrontEnd::create()
{
	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Grey);
	mesh.CreateCube(glm::vec3(0.f, 0.5f, 0.f), glm::vec3(20,0.5,20), Color::Grey);
	std::cout << "pls work" << std::endl;
}

void FrontEnd::Update(float deltaTime)
{
	
}
