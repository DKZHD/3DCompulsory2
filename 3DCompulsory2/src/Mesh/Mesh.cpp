#include "Mesh.h"

#include "../Shaders/Shader.h"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"

void Mesh::CreateCube(glm::vec3 position, glm::vec3 scale, glm::vec3 color)
{

	Package.emplace_back(position, scale);
	Package.back().GetIndex() = Package.size() - 1;

	Vertex v0{0.f, 0.f, 0.f, color}; /* Front-Bot-left */
	Vertex v1{1.f, 0.f, 0.f, color}; /* Front-Bot-right */
	Vertex v2{1.f, 1.f, 0.f, color}; /* Front-Top-right */
	Vertex v3{0.f, 1.f, 0.f, color}; /* Front-Top-left */
	Vertex v4{0.f, 0.f, -1.f, color}; /* Back-Bot-left */
	Vertex v5{1.f, 0.f, -1.f, color}; /* Back-Bot-right */
	Vertex v6{1.f, 1.f, -1.f, color}; /* Back-Top-right */
	Vertex v7{0.f, 1.f, -1.f, color}; /* Back-Top-left */

	mVertices.emplace_back(v0);
	mVertices.emplace_back(v1);
	mVertices.emplace_back(v2);
	mVertices.emplace_back(v3);
	mVertices.emplace_back(v4);
	mVertices.emplace_back(v5);
	mVertices.emplace_back(v6);
	mVertices.emplace_back(v7);
						   
	/* Front */
	mIndices.emplace_back(0);
	mIndices.emplace_back(1);
	mIndices.emplace_back(2);
	mIndices.emplace_back(2);
	mIndices.emplace_back(3);
	mIndices.emplace_back(0);

	/* Right */
	mIndices.emplace_back(1);
	mIndices.emplace_back(5);
	mIndices.emplace_back(6);
	mIndices.emplace_back(6);
	mIndices.emplace_back(2);
	mIndices.emplace_back(1);

	/* Left */
	mIndices.emplace_back(0);
	mIndices.emplace_back(3);
	mIndices.emplace_back(7);
	mIndices.emplace_back(7);
	mIndices.emplace_back(4);
	mIndices.emplace_back(0);

	/* Back */
	mIndices.emplace_back(4);
	mIndices.emplace_back(7);
	mIndices.emplace_back(6);
	mIndices.emplace_back(6);
	mIndices.emplace_back(5);
	mIndices.emplace_back(4);

	/* Top */
	mIndices.emplace_back(3);
	mIndices.emplace_back(2);
	mIndices.emplace_back(6);
	mIndices.emplace_back(6);
	mIndices.emplace_back(7);
	mIndices.emplace_back(3);

	/* Bottom */
	mIndices.emplace_back(0);
	mIndices.emplace_back(4);
	mIndices.emplace_back(5);
	mIndices.emplace_back(5);
	mIndices.emplace_back(1);
	mIndices.emplace_back(0);


}

void Mesh::Draw()
{
	for (auto& cube:Package)
	{
		glm::mat4 model(1.f);
        model = glm::translate(model, cube.GetPosition());
        model = glm::scale(model, cube.GetScale());
        glUniformMatrix4fv(glGetUniformLocation(Shader::Program, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(model));
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)(cube.GetIndex() * 36 * sizeof(unsigned int)));
	}
}
