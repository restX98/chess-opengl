#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 outColor;

void main() {
  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
  outColor = vec4(0.0, 1.0, 0.0, 1.0);
};
