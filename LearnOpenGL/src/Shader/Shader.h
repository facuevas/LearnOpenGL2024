//
// Created by Francis on 1/1/2024.
//

#ifndef LEARNOPENGL2024_SHADER_H
#define LEARNOPENGL2024_SHADER_H

// clang-format off
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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
	void Use();

	/** Uniform Utility Functions */
	void SetInt(const std::string& name, int value) const;
	void SetBool(const std::string& name, bool value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetVec2(const std::string& name, const glm::vec2& value) const;
	void SetVec2(const std::string& name, const float& x, const float& y) const;
	void SetVec3(const std::string& name, const glm::vec3& value) const;
	void SetVec3(const std::string& name, const float& x, const float& y, const float& z) const;
	void SetVec4(const std::string& name, const glm::vec4& value) const;
	void SetVec4(const std::string& name, const float& x, const float& y, const float& z, const float& w) const;
	void SetMat2(const std::string& name, const glm::mat2& value) const;
	void SetMat3(const std::string& name, const glm::mat3& value) const;
	void SetMat4(const std::string& name, const glm::mat4& value) const;

private:
	/** Print Errors */

};

#endif//LEARNOPENGL2024_SHADER_H
