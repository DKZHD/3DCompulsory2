#include "FrontEnd.h"
#include <iostream>
#include "../Color.h"
#include "../NPC/NPC.h"
NPC npc;

Collision collision(glm::vec3(9, 0.5, -6), glm::vec3(2, 2, 1.f));
float timer = 0.f;

void FrontEnd::create()
{
	// Player
	mesh.CreateCube(glm::vec3(0, 0.5, 0.f), glm::vec3(0.75f, 1.3f, 0.75f),Color::Pink, false, true);
	mesh.Package[0]->AddCollider(glm::vec3(0.75, 1.3, 1.2), ECollisionType::Player);

	// Pickups
	mesh.CreateCube(glm::vec3(0.f, 1.f, -10.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(10.f, 1.f, -10.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(-5.f, 1.f, -4.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(5.f, 1.f, 0.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(30.f, 1.f, -10.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(25.f, 1.f, -10.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(-12.f, 1.f, -15.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	mesh.CreateCube(glm::vec3(15.f, 1.f, -7.f), glm::vec3(1.f), Color::Gold, true);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::Pickup);

	// Floor
	mesh.CreateCube(glm::vec3(0.f), glm::vec3(20,0.5,20), Color::Olive);
	mesh.Package.back()->AddCollider(glm::vec3(20, 5.f, 20), ECollisionType::Wall);

	// NPC
	mesh.CreateCube(glm::vec3(10.f, 10.f, -10.f), glm::vec3(1.f), Color::Pink);
	mesh.Package.back()->AddCollider(glm::vec3(1.f),ECollisionType::NPC);

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
	mesh.Package.back()->AddCollider(glm::vec3(2.f,2.f,0.5f), ECollisionType::Door,glm::vec3(0.f,0.f,0.5f));

	//Items in the house
	mesh.CreateCube(glm::vec3(9,0.5,-10), glm::vec3(0.5,0.5,0.5), Color::Red);
	mesh.Package.back()->bShouldRender = false;
	mesh.CreateCube(glm::vec3(7,0.5,-8), glm::vec3(0.5,0.5,0.5), Color::Blue);
	mesh.Package.back()->bShouldRender = false;
	mesh.CreateCube(glm::vec3(11,0.5,-12), glm::vec3(0.5,0.5,0.5), Color::White);
	mesh.Package.back()->bShouldRender = false;

	//NPC
	npc.initNPC();
}

void FrontEnd::Update(float deltaTime)
{
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[1]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[2]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[3]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[4]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[5]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[6]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[7]->Collider);
	mesh.Package[0]->Collider->checkCollision(*mesh.Package[8]->Collider);

	mesh.Package[0]->Collider->checkCollision(*mesh.Package[18]->Collider);

	if(collision.checkCollision(*mesh.Package[0]->Collider))
	{
		for(int i = 19; i < 22; i++)
		{
			mesh.Package[i]->bShouldRender = true;
		}
	}

	npc.updatePos(*mesh.Package[10]);
	if(mesh.Package.back()->bDoorInteracted)
	{
		mesh.Package.back()->GetRotation().y -= 40.f*deltaTime;
	}
	
	
}
