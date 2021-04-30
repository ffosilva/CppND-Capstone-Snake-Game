#include "game.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include "SDL.h"

Game::Game(int grid_width, int grid_height)
        : snake(grid_width, grid_height),
          engine(dev()),
          random_w(0, static_cast<int>(grid_width - 1)),
          random_h(0, static_cast<int>(grid_height - 1)),
          random_bonus(5, 15) { }

void Game::BonusThread() {
    std::unique_lock<std::mutex> uniqueLock(bonusMutex);
    while (running) {
        cv.wait(uniqueLock);
        PlaceFood(FoodKind::SlowDown);
    }
}

void Game::Initialize() {
    if (snake.alive)
        return;

    score = 0;
    scoreSinceBonus = 0;
    hasBonusFood = false;
    nextBonusScore = random_bonus(engine);
    food.clear();
    snake.Reset();

    PlaceFood(FoodKind::Grow);
}

void Game::Run(Renderer &renderer,
               std::size_t target_frame_duration) {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    std::thread t(&Game::BonusThread, this);
    t.detach();

    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        Controller::HandleInput(running, snake, [this] { Initialize(); });
        Update();
        renderer.Render(snake, food);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        if (snake.alive && scoreSinceBonus >= nextBonusScore && !hasBonusFood)
        {
            hasBonusFood = true;
            nextBonusScore = random_bonus(engine);
            std::unique_lock<std::mutex> uniqueLock(bonusMutex);
            cv.notify_one();
        }

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(snake.alive, score, frame_count);
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

    cv.notify_one();
}

void Game::PlaceFood(FoodKind kind) {
    std::scoped_lock<std::mutex> lock(foodMutex);
    int x, y;
    while (true) {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!std::any_of(food.begin(), food.end(),
                         [x, y](Food f) {
                             return f.GetPoint().x == x && f.GetPoint().y == y;
                         }) && !snake.SnakeCell(x, y)) {
            food.emplace_back(Food(x, y, kind));
            return;
        }
    }
}

size_t Game::CheckEat(FoodKind kind) {
    int new_x = static_cast<int>(snake.head_x);
    int new_y = static_cast<int>(snake.head_y);

    auto originalFoodCount = food.size();

    // Check if there's food over here
    food.erase(std::remove_if(food.begin(), food.end(), [new_x, new_y, kind](Food element) {
        return element.GetKind() == kind && element.GetPoint().x == new_x && element.GetPoint().y == new_y;
    }), food.end());

    return originalFoodCount - food.size();
}

void Game::Update() {
    if (!snake.alive) return;

    snake.Update();

    if (CheckEat(FoodKind::Grow) > 0) {
        score++;
        scoreSinceBonus++;
        PlaceFood(FoodKind::Grow);

        // Grow snake and increase speed.
        snake.GrowBody();
        snake.speed += 0.02;
    } else if (CheckEat(FoodKind::SlowDown) > 0) {
        scoreSinceBonus = 0;
        hasBonusFood = false;

        // Decrease speed at half.
        snake.speed /= 2;
    }
}

int Game::GetScore() const { return score; }

int Game::GetSize() const { return snake.size; }