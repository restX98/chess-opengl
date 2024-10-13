#include "Plane.hpp"

Plane::Plane() {
  std::vector<Vertex> vertices;

  // vertices.push_back(Vertex({ glm::vec3(-1.0f, 0.0f, -1.0f) }));
  // vertices.push_back(Vertex({ glm::vec3(1.0f, 0.0f, -1.0f) }));
  // vertices.push_back(Vertex({ glm::vec3(1.0f, 0.0f, 1.0f) }));
  // vertices.push_back(Vertex({ glm::vec3(-1.0f, 0.0f, 1.0f) }));

  // TODO: temporary vertices
  vertices.push_back(Vertex({ glm::vec3(-1.0f, -1.0f, 0.0) }));
  vertices.push_back(Vertex({ glm::vec3(1.0f, -1.0f, 0.0f) }));
  vertices.push_back(Vertex({ glm::vec3(1.0f, 1.0f, 0.0f) }));
  vertices.push_back(Vertex({ glm::vec3(-1.0f, 1.0f, 0.0f) }));

  this->m_meshes.emplace_back(new Mesh(vertices, { 0, 1, 2, 2, 3, 0 }));
}
