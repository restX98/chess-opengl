#pragma once

#include <memory>
#include <vector>

#include "Mesh.hpp"

class Model {
public:
  ~Model() = default;

  virtual void draw(Shader shader, glm::mat4 model = glm::mat4(1.0f));

protected:
  Model() = default;
  std::vector<std::unique_ptr<Mesh>> m_meshes;
};
