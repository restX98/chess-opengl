#include "Model.hpp"

void Model::draw(Shader shader, glm::mat4 model) {
  for (auto const& mesh : this->m_meshes) {
    mesh->draw(shader);
  }
}
