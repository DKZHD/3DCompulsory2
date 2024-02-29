#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex
{
	float x, y , z;
	float v0, v1, v2;
	Vertex(float x, float y, float z, float r, float g, float b) : x(x), y(y), z(z), v0(r), v1(g), v2(b)
	{
	}
};

class Mesh
{
	float a{1.0f};

public:
	std::vector<Vertex> mVertices;
	std::vector<GLuint> mIndices;

	

};

struct Cube : public Mesh
{
private:
	int index = 0;
	glm::vec3 Position;
	unsigned int Program;
	glm::vec3 scale;

public:
	Cube(float x, float y, float z, glm::vec3 scale, const unsigned int& program)
		: Position(x, y, z), Program(program), scale(scale)
	{
	}
	void Draw();
	void TranslateDraw(float x, float y, float z, bool should_stop = false);
	glm::vec3& GetPosition() { return Position; }
	glm::vec3& GetScale() { return scale; }
	int& GetIndex() { return index; }
	float a{1.0f};
	void CreateCube(float size);
};

