#include "renderer.h"
#include "food.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Renderer::Renderer(const int screen_width,
                   const int screen_height,
                   const int grid_width, const int grid_height)
        : screen_width(screen_width),
          screen_height(screen_height),
          grid_width(grid_width),
          grid_height(grid_height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(Snake const &snake, std::vector<Food> &food) {
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render food
    std::for_each(food.begin(), food.end(), [this, &block](Food foodElement) {
        switch (foodElement.GetKind()) {
            case FoodKind::Grow:
                SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
                break;
            case FoodKind::SlowDown:
            default:
                SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0xFF, 0xFF);
        }

        block.x = foodElement.GetPoint().x * block.w;
        block.y = foodElement.GetPoint().y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    });


    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive) {
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
    } else {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(bool gameRunning, int score, int lastScore, int highScore) {
    if (!gameRunning && lastScore <= 0) {
        SDL_SetWindowTitle(sdl_window,
                           std::string(
                                   "Press <ENTER> to start! | SNAKE++ | HIGH SCORE:" + std::to_string(highScore)).c_str());
    } else if (!gameRunning && lastScore > 0) {
        SDL_SetWindowTitle(sdl_window,
                           std::string(
                                   "Press <ENTER> to start! | LAST SCORE: " + std::to_string(lastScore) + " | HIGH SCORE: " + std::to_string(highScore)).c_str());
    } else {
        SDL_SetWindowTitle(sdl_window,
                           std::string(
                                   "SCORE: " + std::to_string(score) + " | SNAKE++ | HIGH SCORE: " + std::to_string(highScore)).c_str());
    }
}
