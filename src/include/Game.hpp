#pragma once

#include <string>
#include <vector>

#include "Camera.hpp"
#include "Model.hpp"
#include "ShaderMgr.hpp"
#include "Window.hpp"

class Game {
public:
  Game(std::string name, int width = 900, int height = 600);

  void run();
  void addModel(Model* model);

private:
  Window* m_window;
  std::vector<std::unique_ptr<Model>> m_models;
};
