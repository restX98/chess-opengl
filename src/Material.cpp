#include "Material.hpp"

Material::Material(Shader* shader, glm::vec3 color)
    : m_shader(shader), m_color(color) {}

void Material::apply() {
  this->m_shader->use();
  this->m_shader->setVec3("color", this->m_color.x, this->m_color.y,
                          this->m_color.z);
}

Shader* Material::getShader() {
  return this->m_shader;
}
