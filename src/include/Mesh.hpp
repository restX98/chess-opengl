#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "Shader.hpp"

struct Vertex {
  glm::vec3 Position;
  glm::vec3 Normal;
  glm::vec2 TexCoords;
  glm::vec3 Tangent;
  glm::vec3 Bitangent;
};

class Mesh {
private:
  void setup();

public:
  Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indexes);
  ~Mesh();

  void draw(Shader& shader);

protected:
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;

  std::vector<Vertex> vertices;
  std::vector<unsigned int> indexes;
};
