#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex
{
	float x, y, z;
};

class Mesh
{
public:
	std::vector<Vertex> mVertices;
	std::vector<GLuint> mIndices;
};

