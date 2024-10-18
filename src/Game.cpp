#include "Game.hpp"

Game::Game(std::string name, int width, int height)
    : m_window(new Window(name.c_str(), width, height)) {
  this->m_window->setEventCallback()
}

void Game::addModel(Model* model) {
  this->m_models.emplace_back(model);
}

void Game::run() {
  glEnable(GL_DEPTH_TEST);

  while (!this->m_window->shouldClose()) {
    this->m_window->setBackgroundColor(1.0f, 0.0f, 0.0f);
    this->m_window->clearBuffers();

    for (auto const& model : this->m_models) {
      model->draw();
    }

    this->m_window->update();
  }
}

void Game::onEvent(Event& e) {}
