#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"

class Game {
public:
    Game(int grid_width, int grid_height);

    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration);

    int GetScore() const;

    int GetSize() const;

private:
    Snake snake;

    std::vector<Food> food;
    std::mutex foodMutex, bonusMutex;
    std::condition_variable cv;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};
    bool running{true};

    int scoreSinceBonus{0};
    bool hasBonusFood{false};
    std::uniform_int_distribution<int> random_bonus;


    void PlaceFood(FoodKind kind);

    size_t CheckEat(FoodKind kind);

    void BonusThread();

    void Update();
};

#endif