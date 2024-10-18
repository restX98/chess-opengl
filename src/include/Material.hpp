#pragma once

#include "Shader.hpp"

class Material {
public:
  Material(Shader* shader, glm::vec3 color);
  ~Material();

  void apply();
  Shader* getShader();

private:
  Shader* m_shader;
  glm::vec3 m_color;
};
