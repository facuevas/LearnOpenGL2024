//
// Created by Francis on 1/1/2024.
//

#include "Shader.h"
Shader::Shader(const char* vertPath, const char* fragPath)
{
	// Retrieve the Vertex and Fragment source from the file path.
	std::string vertCode;
	std::string fragCode;
	std::ifstream vertFile;
	std::ifstream fragFile;

	// Make sure ifstream objects can throw exceptions.
	vertFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertFile.open(vertPath);
		fragFile.open(fragPath);
		std::stringstream vertStream, fragStream;
		vertStream << vertFile.rdbuf();
		fragStream << fragFile.rdbuf();
		vertFile.close();
		fragFile.close();
		vertCode = vertStream.str();
		fragCode = fragStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR - Shader File Not Successfully Read" << std::endl;
	}

	// Compile Shaders
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexCode = vertCode.c_str();
	glShaderSource(vertex, 1, &vertexCode, nullptr);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
		std::cout << "ERROR - Vertex Compilation Failed" << infoLog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentCode = fragCode.c_str();
	glShaderSource(fragment, 1, &fragmentCode, nullptr);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
		std::cout << "ERROR - Fragment Compilation Failed" << infoLog << std::endl;
	}

	// Shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, nullptr, infoLog);
		std::cout << "ERROR - Shader Linking Failed" << infoLog << std::endl;
	}

	// Cleanup
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
