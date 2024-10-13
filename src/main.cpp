#include <iostream>

#include "Window.hpp"
#include "Shader.hpp"
#include "Plane.hpp"

int main() {

  Window window("Chess", 500, 500);

  Shader shader(SHADERS_PATH "basic_shader.vert", SHADERS_PATH "shader.frag");

  Plane plane;

  window.run(
    [&plane, &shader]() {
      plane.draw(shader);
    }
  );

  return 0;
}
