#include "FrontEnd.h"

#include <iostream>

#include "../Color.h"

void FrontEnd::initialize()
{
	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Grey);
	std::cout << "pls work" << std::endl;
}

void FrontEnd::Update(float deltaTime)
{
	
}
