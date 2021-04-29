#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "food.h"

class Renderer {
 public:
  Renderer(int screen_width, int screen_height,
           int grid_width, int grid_height);
  ~Renderer();

  void Render(const Snake& snake, Food &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const int screen_width;
  const int screen_height;
  const int grid_width;
  const int grid_height;
};

#endif