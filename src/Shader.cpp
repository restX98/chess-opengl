#include "Shader.hpp"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;

  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);

    std::stringstream vShaderStream, fShaderStream;

    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vShaderFile.close();
    fShaderFile.close();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  } catch (std::ifstream::failure e) {
    std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
  }

  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  unsigned int vertex, fragment;

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, nullptr);
  glCompileShader(vertex);
  this->checkCompileErrors(vertex, "VERTEX");

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, nullptr);
  glCompileShader(fragment);
  this->checkCompileErrors(fragment, "FRAGMENT");

  this->m_ID = glCreateProgram();
  glAttachShader(this->m_ID, vertex);
  glAttachShader(this->m_ID, fragment);
  glLinkProgram(this->m_ID);
  this->checkCompileErrors(this->m_ID, "PROGRAM");

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

Shader::~Shader() {
  glDeleteProgram(this->m_ID);
  glDeleteProgram(this->ID);
}

void Shader::use() {
  glUseProgram(this->m_ID);
}

void Shader::setBool(const std::string& name, bool value) {
  int attributeLocation = glGetUniformLocation(this->m_ID, name.c_str());
  glUniform1i(attributeLocation, (int)value);
}

void Shader::setInt(const std::string& name, int value) {
  int attributeLocation = glGetUniformLocation(this->m_ID, name.c_str());
  glUniform1i(attributeLocation, value);
}

void Shader::setFloat(const std::string& name, float value) {
  int attributeLocation = glGetUniformLocation(this->m_ID, name.c_str());
  glUniform1f(attributeLocation, value);
}

void Shader::setVec2(const std::string& name, const glm::vec2& value) const {
  glUniform2fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec2(const std::string& name, float x, float y) const {
  glUniform2f(glGetUniformLocation(m_ID, name.c_str()), x, y);
}
void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
  glUniform3fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string& name, float x, float y, float z) const {
  glUniform3f(glGetUniformLocation(m_ID, name.c_str()), x, y, z);
}
void Shader::setVec4(const std::string& name, const glm::vec4& value) const {
  glUniform4fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec4(const std::string& name, float x, float y, float z,
                     float w) const {
  glUniform4f(glGetUniformLocation(m_ID, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string& name, const glm::mat2& mat) const {
  glUniformMatrix2fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE,
                     &mat[0][0]);
}
void Shader::setMat3(const std::string& name, const glm::mat3& mat) const {
  glUniformMatrix3fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE,
                     &mat[0][0]);
}
void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
  glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE,
                     &mat[0][0]);
}


void Shader::checkCompileErrors(unsigned int shader, std::string type) {
  int success;
  char infoLog[512];

  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "ERROR::SHADER::SHADER_COMPILATION_ERROR of type: " << type
                << "\n";
      std::cout
          << infoLog
          << "\n -- --------------------------------------------------- -- "
          << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM_LINKING_ERROR of type: " << type
                << "\n";
      std::cout
          << infoLog
          << "\n -- --------------------------------------------------- -- "
          << std::endl;
    }
  }
}
