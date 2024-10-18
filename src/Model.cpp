#include "Model.hpp"

void Model::setMaterial(Material* material) {
  this->m_material = material;
}

void Model::draw(glm::mat4 model) {
  this->m_material->apply();
  for (auto const& mesh : this->m_meshes) {
    mesh->draw(*this->m_material->getShader());
  }
}
