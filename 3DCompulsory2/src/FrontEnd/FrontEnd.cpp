#include "FrontEnd.h"
#include <iostream>
#include "../Color.h"

void FrontEnd::create()
{
	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Blue);
	mesh.CreateCube(glm::vec3(0.f, 3.f, 0.f), glm::vec3(10,2,10), Color::Pink);
	std::cout << "pls work" << std::endl;
}

void FrontEnd::Update(float deltaTime)
{
	
}
