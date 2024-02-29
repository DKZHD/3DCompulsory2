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

struct triangle
{
	float a{1.0f};
	std::vector<Vertex> tVertices;
	std::vector<GLuint> tIndices;
	void CreateTriangle(float size);
};

struct Square
{
	float a{1.0f};
	std::vector<Vertex> sVertices;
	std::vector<GLuint> sIndices;
	void CreateSquare(float size);
};

struct Cube
{
	float a{1.0f};
	std::vector<Vertex> cVertices;
	std::vector<GLuint> cIndices;
	void CreateTriangle(float size);
};

