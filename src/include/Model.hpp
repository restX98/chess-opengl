#pragma once

#include <memory>
#include <vector>

#include "Material.hpp"
#include "Mesh.hpp"

class Model {
public:
  ~Model() = default;

  void setMaterial(Material* material);
  virtual void draw(glm::mat4 model = glm::mat4(1.0f));

protected:
  Model() = default;

  Material* m_material;
  std::vector<std::unique_ptr<Mesh>> m_meshes;
};
