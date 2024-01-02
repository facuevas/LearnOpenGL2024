//
// Created by Francis on 1/1/2024.
//

#ifndef LEARNOPENGL2024_SHADER_H
#define LEARNOPENGL2024_SHADER_H

// clang-format off
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
// clang-format on

class Shader
{
public:
	/** Shader Program ID */
	unsigned int ID;

	/** Constructor needs path to Vertex and Fragment shaders*/
	Shader(const char* vertPath, const char* fragPath);

	/** Used to activate the Shader */
	void use();

	/** Uniform Utility Functions */
	void setInt(const std::string& name, int value) const;
	void setBool(const std::string& name, bool value) const;
	void setFloat(const std::string& name, float value) const;
};

#endif//LEARNOPENGL2024_SHADER_H
