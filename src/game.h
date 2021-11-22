#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "player.h"
#include "renderer.h"
#include "snake.h"
#include <random>

class Game {
public:
  Game(std::size_t grid_width, std::size_t grid_height, Player *p1, Player *p2);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

private:
  Snake snake1;
  Snake snake2;
  SDL_Point food;

  Player *p1;
  Player *p2;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void checkIfSnakesCrash();
  void checkIfFoodConsumed(Snake *s, Player *p);
  void PlaceFood();
  int Update();
};

#endif
