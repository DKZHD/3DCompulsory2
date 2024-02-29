#include "Mesh.h"

void triangle::CreateTriangle(float size)
{
	a = size;
	Vertex v0{-a, a, a, 1.0f, 0.f, 0.f};
	Vertex v1{-a, -a, a, 1.0f, 0.f, 0.f};
	Vertex v2{a, -a, a, 1.0f, 0.f, 0.f};

	tIndices.emplace_back(0);
	tIndices.emplace_back(1);
	tIndices.emplace_back(2);
}
