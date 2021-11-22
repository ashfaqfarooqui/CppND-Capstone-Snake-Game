#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"
#include "player.h"
#include <vector>

class Snake {
public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  // Start pos x and y take a value between 1 -10
  Snake(int grid_width, int grid_height, int startpos_x, int startpos_y)
      : grid_width(grid_width), grid_height(grid_height),
        head_x(grid_width * startpos_x / 10),
        head_y(grid_height * startpos_y / 10) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
