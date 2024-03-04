#include "FrontEnd.h"
#include <iostream>
#include "../Color.h"
#include "../NPC/NPC.h"
NPC npc;

void FrontEnd::create()
{
	// Player
	mesh.CreateCube(glm::vec3(0, 0.5, 0.f), glm::vec3(0.75f, 1.3f, 0.75f), Color::White, true);
	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Blue);
	mesh.Package.back().AddCollider(glm::vec3(20, 5.f, 20));
	mesh.CreateCube(glm::vec3(10.f, 10.f, -10.f), glm::vec3(1.f), Color::Pink);
	mesh.Package.back().AddCollider(glm::vec3(1.f));

	//NPC
	npc.initNPC();
}

void FrontEnd::Update(float deltaTime)
{
	npc.updatePos(mesh.Package.back());
}
