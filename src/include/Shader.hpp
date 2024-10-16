#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
protected:
  GLuint m_ID;

public:

  Shader(const std::string& vertexPath, const std::string& fragmentPath);
  ~Shader();

  void use();

  void setBool(const std::string& name, bool value);
  void setInt(const std::string& name, int value);
  void setFloat(const std::string& name, float value);

  void setVec2(const std::string& name, const glm::vec2& value) const;
  void setVec2(const std::string& name, float x, float y) const;
  void setVec3(const std::string& name, const glm::vec3& value) const;
  void setVec3(const std::string& name, float x, float y, float z) const;
  void setVec4(const std::string& name, const glm::vec4& value) const;
  void setVec4(const std::string& name, float x, float y, float z,
               float w) const;

  void setMat2(const std::string& name, const glm::mat2& mat) const;
  void setMat3(const std::string& name, const glm::mat3& mat) const;
  void setMat4(const std::string& name, const glm::mat4& mat) const;

  void setViewProjectionMatrices(const glm::mat4& view,
                                 const glm::mat4& projection);

private:
  void checkCompileErrors(unsigned int shader, std::string type);
};
