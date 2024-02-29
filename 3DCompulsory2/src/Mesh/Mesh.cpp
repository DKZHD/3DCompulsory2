#include "Mesh.h"

void Mesh::triangle(float size)
{
	a = size;
	Vertex v0{-a, a, a, 1.0f, 0.f, 0.f};
	Vertex v1{-a, -a, a, 1.0f, 0.f, 0.f};
	Vertex v2{a, -a, a, 1.0f, 0.f, 0.f};

	mIndices.emplace_back(0);
	mIndices.emplace_back(1);
	mIndices.emplace_back(2);
}
