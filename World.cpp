#include "World.h"

GameObject* World::world[World::size];

std::default_random_engine World::dre;
std::uniform_int_distribution<int> World::random_point { World::min_x, World:: max_x };