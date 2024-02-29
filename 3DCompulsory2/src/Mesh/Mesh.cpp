#include "Mesh.h"

void Cube::CreateCube(float size)
{
	a = size;
	Vertex v0 {-a, -a, a, 1.0f, 0.0f, 0.0f};
	Vertex v1{a, -a, a, 1.0f, 0.0f, 0.0f};
	Vertex v2{a, a, a, 1.0f, 0.0f, 0.0f};
	Vertex v3{-a, a, a, 1.0f, 0.0f, 0.0f};
	Vertex v4{a, -a, -a, 1.0f, 0.0f, 0.0f};
	Vertex v5{a, a, -a, 1.0f, 0.0f, 0.0f};
	Vertex v6{-a, -a, -a, 1.0f, 0.0f, 0.0f};
	Vertex v7{-a, a, -a, 1.0f, 0.0f, 0.0f};

	//cIndices.emplace_back(0);
	//cIndices.emplace_back(1);
	//cIndices.emplace_back(3);
	//cIndices.emplace_back(3);
	//cIndices.emplace_back(1);
	//cIndices.emplace_back(2);
	//cIndices.emplace_back(1);
	//cIndices.emplace_back(4);
	//cIndices.emplace_back(2);
	//cIndices.emplace_back(2);
	//cIndices.emplace_back(4);
	//cIndices.emplace_back(5);
	//cIndices.emplace_back(6);
	//cIndices.emplace_back(5);
	//cIndices.emplace_back(5);
	//cIndices.emplace_back(6);
	//cIndices.emplace_back(7);
	//cIndices.emplace_back(6);
	//cIndices.emplace_back(0);
	//cIndices.emplace_back(7);
	//cIndices.emplace_back(7);
	//cIndices.emplace_back(0);
	//cIndices.emplace_back(3);
	//cIndices.emplace_back(3);
	//cIndices.emplace_back(2);
	//cIndices.emplace_back(5);
	//cIndices.emplace_back(5);
	//cIndices.emplace_back(2);
	//cIndices.emplace_back(7);
	//cIndices.emplace_back(0);
	//cIndices.emplace_back(1);
	//cIndices.emplace_back(4);
	//cIndices.emplace_back(4);
	//cIndices.emplace_back(0);
	//cIndices.emplace_back(6);

	///* Front */
	//cVertices.emplace_back(v0);
	//cVertices.emplace_back(v1);
	//cVertices.emplace_back(v3);
	//cVertices.emplace_back(v3);
	//cVertices.emplace_back(v1);
	//cVertices.emplace_back(v2);

	///* Right */
	//cVertices.emplace_back(v1);
	//cVertices.emplace_back(v4);
	//cVertices.emplace_back(v2);
	//cVertices.emplace_back(v2);
	//cVertices.emplace_back(v4);
	//cVertices.emplace_back(v5);

	///* Back */
	//cVertices.emplace_back(v4);
	//cVertices.emplace_back(v6);
	//cVertices.emplace_back(v5);
	//cVertices.emplace_back(v5);
	//cVertices.emplace_back(v6);
	//cVertices.emplace_back(v7);

	///* Left */
	//cVertices.emplace_back(v6);
	//cVertices.emplace_back(v0);
	//cVertices.emplace_back(v7);
	//cVertices.emplace_back(v7);
	//cVertices.emplace_back(v0);
	//cVertices.emplace_back(v3);

	///* Top */
	//cVertices.emplace_back(v3);
	//cVertices.emplace_back(v2);
	//cVertices.emplace_back(v5);
	//cVertices.emplace_back(v5);
	//cVertices.emplace_back(v2);
	//cVertices.emplace_back(v7);

	///* Bottom */
	//cVertices.emplace_back(v0);
	//cVertices.emplace_back(v1);
	//cVertices.emplace_back(v4);
	//cVertices.emplace_back(v4);
	//cVertices.emplace_back(v1);
	//cVertices.emplace_back(v6);

}
void Cube::Draw()
{
	
}
;


