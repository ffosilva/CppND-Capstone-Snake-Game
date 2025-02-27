//
// Created by ffosilva on 29/04/2021.
//

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include "SDL.h"

enum FoodKind {
    None,
    Grow,
    SlowDown
};

class Food {
private:
    SDL_Point _point{};
    FoodKind _kind;

public:
    Food(int x, int y, FoodKind kind);

    Food();

    SDL_Point GetPoint();

    FoodKind GetKind();
};


#endif //SDL2TEST_FOOD_H
