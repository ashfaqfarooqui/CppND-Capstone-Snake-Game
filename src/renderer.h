#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "snake.h"
#include <vector>

class Renderer {
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake1, SDL_Point const &food, Snake const snake2);
  void UpdateWindowTitle(std::string s1, std::string s2, int fps);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  void renderSnake(Snake const snake, uint8_t r, uint8_t g, uint8_t b,
                   uint8_t d, SDL_Rect &block);

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
