#pragma once
#include <string>
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

struct Cube;

class Mesh
{
private:
	int count;

public:
	std::vector<Vertex> mVertices;
	std::vector<GLuint> mIndices;
	std::vector<Cube> Package;
	

	void Draw();
	void CreateCube(glm::vec3 position, glm::vec3 scale, glm::vec3 color);
};

struct Cube : public Mesh
{
private:
	int index = 0;
	glm::vec3 Position;
	glm::vec3 scale;

public:
	Cube(glm::vec3 position, glm::vec3 scale)
		: Position(position), scale(scale)
	{
	}
	bool bIsPlayer;
	glm::vec3& GetPosition() { return Position; }
	glm::vec3& GetScale() { return scale; }
	int& GetIndex() { return index; }
	float a{1.0f};
	
};

