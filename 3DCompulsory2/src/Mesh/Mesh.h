#pragma once
#include <memory>
#include "../Collision/Collision.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Pickup;

struct Vertex
{
	float x, y, z;
	glm::vec3 Color;
	Vertex(float x, float y, float z, glm::vec3 rgb) : x(x), y(y), z(z), Color(rgb)
	{
	}
};

class Cube;

class Mesh
{
	int count;

public:
	std::vector<Vertex> mVertices;
	std::vector<GLuint> mIndices;
	std::vector<std::shared_ptr<Cube>> Package;
	

	void Draw();
	void CreateCube(glm::vec3 position, glm::vec3 scale, glm::vec3 color, bool isPickup = false ,bool isPlayer = false);
};

class Cube : Mesh
{
	int index = 0;
	glm::vec3 Position;
	glm::vec3 Scale;

public:
	Cube(glm::vec3 position, glm::vec3 scale)
		: Position(position), Scale(scale)
	{
		
	}
	bool bIsPlayer = false;
	bool bCanInteract = false;
	bool bIsPickup = false;
	bool bShouldRender = true;

	Cube* OverlappedCube;

	std::unique_ptr<Collision> Collider;
	glm::vec3& GetPosition() { return Position; }
	glm::vec3& GetScale() { return Scale; }
	int& GetIndex() { return index; }
	void AddCollider(glm::vec3 scale);
	virtual ~Cube();
};


