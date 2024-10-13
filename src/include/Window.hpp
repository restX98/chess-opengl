#pragma once

#include <iostream>
#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
  Window(const char* title, int width = 1920, int height = 1080);
  ~Window();

  void run();

private:
  bool shouldClose();

protected:
  GLFWwindow* m_window;
};
