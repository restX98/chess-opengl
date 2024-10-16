#pragma once

#include <functional>
#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Window {
public:
  Window(const char* title, int width = 1920, int height = 1080);
  ~Window();

  void update();
  bool shouldClose();
  void clearBuffers();
  void setBackgroundColor(float red, float green, float blue);

protected:
  GLFWwindow* m_window;
};
