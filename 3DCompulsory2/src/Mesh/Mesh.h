#pragma once
#include <memory>
#include <string>
#include "../Collision/Collision.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

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
private:
	int count;

public:
	std::vector<Vertex> mVertices;
	std::vector<GLuint> mIndices;
	std::vector<Cube> Package;
	

	void Draw();
	void CreateCube(glm::vec3 position, glm::vec3 scale, glm::vec3 color, bool isPlayer = false);
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

	std::shared_ptr<Collision> Collider;
	glm::vec3& GetPosition() { return Position; }
	glm::vec3& GetScale() { return Scale; }
	int& GetIndex() { return index; }
	void AddCollider(glm::vec3 scale);
	virtual ~Cube();
};

