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

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, const glm::vec2& value) const
{
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec2(const std::string& name, const float& x, const float& y) const
{
	glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec3(const std::string& name, const float& x, const float& y, const float& z) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string& name, const glm::vec4& value) const
{
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec4(const std::string& name, const float& x, const float& y, const float& z, const float& w) const
{
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string& name, const glm::mat2& value) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void Shader::SetMat3(const std::string& name, const glm::mat3& value) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}