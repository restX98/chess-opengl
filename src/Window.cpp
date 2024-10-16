#include "Window.hpp"

Window::Window(const char* title, int width, int height) {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  this->m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (this->m_window == nullptr) {
    std::cerr << "ERROR:WINDOW::GLFW_CREATE_WINDOW_FAILED" << std::endl;
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(this->m_window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "ERROR:WINDOW::GLAD_INIT_FAILED" << std::endl;
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
    return;
  }
}

Window::~Window() {
  glfwDestroyWindow(this->m_window);
  glfwTerminate();
}

bool Window::shouldClose() {
  return glfwWindowShouldClose(this->m_window);
}

void Window::clearBuffers() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::setBackgroundColor(float red, float green, float blue) {
  glClearColor(red, green, blue, 1.0f);
}

void Window::update() {
  glfwSwapBuffers(this->m_window);
  glfwPollEvents();
}
