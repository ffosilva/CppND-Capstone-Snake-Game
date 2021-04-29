//
// Created by ffosilva on 29/04/2021.
//

#include "food.h"

Food::Food(int x, int y, FoodKind kind) : _point(SDL_Point{.x = x, .y = y}), _kind(kind) {}

SDL_Point Food::GetPoint() { return _point; }

FoodKind Food::GetKind() { return _kind; }