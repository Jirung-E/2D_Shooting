#pragma once

#include "GameObject.h"

#include <random>


namespace World {
	const int min_x = 0;
	const int max_x = 85;
	const int size = max_x - min_x + 1;
	const int ground_y = 10;
	const char ground = '_';

	const int fps = 120;

	extern GameObject* world[size];

	extern std::default_random_engine dre;
	extern std::uniform_int_distribution<int> random_point;
}