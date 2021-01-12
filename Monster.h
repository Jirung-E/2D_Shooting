#pragma once

#include "LifeObject.h"

#include "Coin.h"

#include <chrono>


class Monster : public LifeObject {
	const char monster = 'M';

	int atk_power;

	bool spawned;
	int spawn_point;
	float move_speed;	// m/s		글자 한칸을 1m라고 정하자.
	std::chrono::system_clock::time_point last_move;

	Coin* coin;

public:
	Monster();
	Monster(int position);
	~Monster();

	float moveSpeed() const;

	void attack(GameObject* go);

	void go();

	int random_spawn_point() const;

	void spawn();

	void interaction(GameObject* go);

	void getDamage(int dmg);

	void die();

	void update();
};