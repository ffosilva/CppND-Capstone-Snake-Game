#include "snake.h"
#include <functional>
#include <cmath>
#include <algorithm>

void Snake::Update() {
    SDL_Point prev_cell{
            static_cast<int>(head_x),
            static_cast<int>(head_y)};  // We first capture the head's cell before updating.
    UpdateHead();
    SDL_Point current_cell{
            static_cast<int>(head_x),
            static_cast<int>(head_y)};  // Capture the head's cell after updating.

    // Update all of the body vector items if the snake head has moved to a new
    // cell.
    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
        UpdateBody(current_cell, prev_cell);
    }
}

void Snake::UpdateHead() {
    switch (direction) {
        case Direction::kUp:
            head_y -= speed;
            break;

        case Direction::kDown:
            head_y += speed;
            break;

        case Direction::kLeft:
            head_x -= speed;
            break;

        case Direction::kRight:
            head_x += speed;
            break;
    }

    // Wrap the Snake around to the beginning if going off of the screen.
    head_x = (float) fmod(head_x + (float) grid_width, grid_width);
    head_y = (float) fmod(head_y + (float) grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
    // Add previous head location to vector
    body.push_back(prev_head_cell);

    if (!growing) {
        // Remove the tail from the vector.
        body.erase(body.begin());
    } else {
        growing = false;
        size++;
    }

    // Check if the snake has died.
    if (std::any_of(body.begin(), body.end(), [current_head_cell](auto const &item) {
        return current_head_cell.x == item.x && current_head_cell.y == item.y;
    })) {
        alive = false;
        if (OnSnakeDieListener != nullptr)
        {
            OnSnakeDieListener();
        }
    }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
    if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
        return true;
    }

    return std::any_of(body.begin(), body.end(), [x, y](auto item) { return x == item.x && y == item.y; });
}

void Snake::Reset() {
    speed = 0.1f;
    size = 1;
    head_x = ((float) grid_width / 2);
    head_y = ((float) grid_height / 2);
    growing = false;
    body.clear();
    alive = true;
}
