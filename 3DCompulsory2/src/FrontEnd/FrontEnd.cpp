#include "FrontEnd.h"
#include <iostream>
#include "../Color.h"
#include "../NPC/NPC.h"
NPC npc;

void FrontEnd::create()
{
	// Player
	mesh.CreateCube(glm::vec3(0, 0.5, 0.f), glm::vec3(0.75f, 1.3f, 0.75f), Color::White, false,true);
	mesh.Package[0]->AddCollider(glm::vec3(0.75, 1.3, 1.2));

	mesh.CreateCube(glm::vec3(0.f, 1.f, -10.f), glm::vec3(1.f), Color::Magenta);
	mesh.Package[1]->AddCollider(glm::vec3(1.f));

	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Blue);
	mesh.Package[2]->AddCollider(glm::vec3(20, 5.f, 20));

	mesh.CreateCube(glm::vec3(10.f, 10.f, -10.f), glm::vec3(1.f), Color::Pink);
	mesh.Package[3]->AddCollider(glm::vec3(1.f));

	//NPC
	npc.initNPC();
}

void FrontEnd::Update(float deltaTime)
{
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[1]->Collider);
	npc.updatePos(*mesh.Package.back());
}
