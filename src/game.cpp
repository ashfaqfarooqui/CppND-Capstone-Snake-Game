#include "game.h"
#include "SDL.h"
#include <chrono>
#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height, Player *p1,
           Player *p2)
    : snake1(grid_width, grid_height, 3, 3),
      snake2(grid_width, grid_height, 6, 6), p1(p1), p2(p2), engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake1, snake2);
    running = Update();
    renderer.Render(snake1, food, snake2);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(p1->getString(), p2->getString(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;

  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake1.SnakeCell(x, y) && !snake2.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

int Game::Update() {

  checkIfSnakesCrash();
  if (!snake1.alive || !snake2.alive) {
    return false;
  } else {
    snake1.Update();

    snake2.Update();

    // Check if there's food over here
    checkIfFoodConsumed(&snake1, p1);

    checkIfFoodConsumed(&snake2, p2);
    return true;
  }
}
void Game::checkIfSnakesCrash() {
  if (static_cast<int>(snake1.head_x) == static_cast<int>(snake2.head_x) &&
      static_cast<int>(snake1.head_y) == static_cast<int>(snake2.head_y)) {

    std::cout << "Snake 1 dead, snake 2 dead\n";
    snake1.alive = false;
    snake2.alive = false;
    return;
  }
  if (snake1.SnakeCell(snake2.head_x, snake2.head_y)) {

    snake2.alive = false;
  }
  if (snake2.SnakeCell(snake1.head_x, snake1.head_y)) {

    snake1.alive = false;
  }
}
void Game::checkIfFoodConsumed(Snake *s, Player *p) {

  int new1_x = static_cast<int>(s->head_x);
  int new1_y = static_cast<int>(s->head_y);

  if (food.x == new1_x && food.y == new1_y) {
    p->incrementScore();

    // score++;
    PlaceFood();
    // Grow snake and increase speed.
    s->GrowBody();
    s->speed += 0.02;
  }
}
int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake1.size; }
