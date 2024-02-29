#pragma once
#include <vector>

struct Vertex;

class VertexArray
{
public:
	unsigned int va;
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;
	void Activate() const;
};

class VertexBuffer
{
public:
	unsigned int vbo;
	VertexBuffer() = default;
	VertexBuffer(std::vector<Vertex>& objectVector);
	~VertexBuffer();
	void Bind(std::vector<Vertex>& objectVector) const;
};
class ElementBuffer
{
public:
	unsigned int ebo;
	ElementBuffer() = default;
	ElementBuffer(std::vector<unsigned int>& objectVector);
	~ElementBuffer();
	void Bind(std::vector<unsigned int>& objectVector) const;
};

