#include <Mesh.hpp>

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indexes)
    : vertices(vertices), indexes(indexes) {
  this->setup();
}

Mesh::~Mesh() {
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
}

void Mesh::setup() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0],
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes.size() * sizeof(unsigned int),
               &indexes[0], GL_STATIC_DRAW);

  // vertex positions
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);
}

void Mesh::draw(Shader& shader) {
  shader.use();

  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, indexes.size(), GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}
