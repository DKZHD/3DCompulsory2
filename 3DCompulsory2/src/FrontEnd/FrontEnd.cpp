#include "FrontEnd.h"
#include <iostream>
#include "../Color.h"
#include "../NPC/NPC.h"
NPC npc;

Collision collision(glm::vec3(9, 0.5, -6), glm::vec3(2, 2, 1.f), nullptr);
float timer = 0.f;

void FrontEnd::create()
{
	// Player
	mesh.CreateCube(glm::vec3(0, 0.5, 0.f), glm::vec3(0.75f, 1.3f, 0.75f),Color::Pink, false, true);
	mesh.Package[0]->AddCollider(glm::vec3(0.75, 1.3, 1.2));

	// Random
	mesh.CreateCube(glm::vec3(0.f, 1.f, -10.f), glm::vec3(1.f), Color::Magenta, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f));

	mesh.CreateCube(glm::vec3(10.f, 1.f, -10.f), glm::vec3(1.f), Color::Yellow, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f));

	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Blue);
	mesh.Package.back()->AddCollider(glm::vec3(20, 5.f, 20));

	mesh.CreateCube(glm::vec3(10.f, 10.f, -10.f), glm::vec3(1.f), Color::Pink);
	mesh.Package.back()->AddCollider(glm::vec3(1.f));

	// House - Walls
	mesh.CreateCube(glm::vec3(15, 0.5, -5), glm::vec3(0.1, 2.5, 10), Color::Brown);
	mesh.CreateCube(glm::vec3(5, 0.5, -15), glm::vec3(10, 2.5, 0.1), Color::Brown);
	mesh.CreateCube(glm::vec3(5, 0.5, -5), glm::vec3(0.1, 2.5, 10), Color::Brown);

	// House - Roof
	mesh.CreateCube(glm::vec3(5, 3, -5), glm::vec3(10.1, 0.1, 10), Color::Brown);

	// House - DoorFrame
	mesh.CreateCube(glm::vec3(5, 0.5, -5), glm::vec3(4, 2.5, 0.1), Color::Brown);
	mesh.CreateCube(glm::vec3(11, 0.5, -5), glm::vec3(4, 2.5, 0.1), Color::Brown);
	mesh.CreateCube(glm::vec3(9, 2.5, -5), glm::vec3(2, 0.5, 0.1), Color::Brown);

	// Door
	mesh.CreateCube(glm::vec3(9, 0.5, -5), glm::vec3(2, 2, 0.1), Color::Maroon, false, false,glm::vec3(0.f,1.f,0.f),true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f));

	//NPC
	npc.initNPC();
}

void FrontEnd::Update(float deltaTime)
{
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[1]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[2]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package.back()->Collider);
	collision.checkCollision(*mesh.Package[0]->Collider);
	std::cout << collision.min.z << "  " << collision.max.z << std::endl;
	npc.updatePos(*mesh.Package[4]);
	if(mesh.Package.back()->bDoorInteracted)
	{
		mesh.Package.back()->GetRotation().y -= 40.f*deltaTime;
	}
	std::cout << "Camera Position: " << Backend::camera.cameraPos.x << " " << Backend::camera.cameraPos.y << " " << Backend::camera.cameraPos.z << std::endl;
	if(collision.bIsCameraLock)
	{
		Backend::camera.cameraPos = glm::vec3(14.8f, 2.5f, -5.2f);
		// collision.lerp(collision.originalCameraPos, glm::vec3(14.8f, 2.5f, -5.2f), timer+=deltaTime);
	}
	
	
}
