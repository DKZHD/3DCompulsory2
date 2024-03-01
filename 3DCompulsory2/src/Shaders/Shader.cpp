#include "Shader.h"
#include <sstream>
#include <fstream>


ShaderSource Shader::ReadShaderFromFile(const char* filepathVert, const char* filepathFrag)
{
	ShaderSource currentSource;
	std::ifstream InFileVert(filepathVert);
	std::ifstream InFileFrag(filepathFrag);
	std::stringstream ssVert;
	std::stringstream ssFrag;
	if(InFileVert.is_open()&&InFileFrag.is_open())
	{
		ssVert << InFileVert.rdbuf();
		ssFrag << InFileFrag.rdbuf();
		currentSource.VertSource = ssVert.str();
		currentSource.FragSource = ssFrag.str();
		return currentSource;
	}
	return {};
}
GLuint Shader::Program;
void Shader::CreateProgram()
{
	ShaderSource source = ReadShaderFromFile("src/Shaders/VertexShader.vert", "src/Shaders/FragmentShader.frag");
	Program = glCreateProgram();
	const char* VertexSource = source.VertSource.c_str();
	const char* FragmentSource = source.FragSource.c_str();
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vs, 1, &VertexSource, nullptr);
	glCompileShader(vs);
	glShaderSource(fs, 1, &FragmentSource, nullptr);
	glCompileShader(fs);
	glAttachShader(Program, vs);
	glAttachShader(Program, fs);
	glLinkProgram(Program);
	glDeleteShader(vs);
	glDeleteShader(fs);
}
