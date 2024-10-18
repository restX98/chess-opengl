#version 330 core

in vec4 outColor;

uniform vec3 color;

out vec4 FragColor;

void main() {
  FragColor = vec4(color, 1.0);
}
