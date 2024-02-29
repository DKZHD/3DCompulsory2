#pragma once
#include <string>
#include <glad/glad.h>

struct ShaderSource
{
	std::string VertSource;
	std::string FragSource;
};

class Shader
{
public:
	static GLuint Program;
	ShaderSource ReadShaderFromFile(const char* filepathVert, const char* filepathFrag);
	void CreateProgram();
};

