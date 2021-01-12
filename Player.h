#pragma once

#include "LifeObject.h"

#include "Bullet.h"


class Player : public LifeObject {
	const char player_r = 'p';
	const char player_l = 'q';

	size_t coin;

	const size_t capacity;
	

public:
	Bullet bullet[80];


	Player();
	//~Player();


	void move_l();
	void move_r();

	void getCoin();

	void shoot();

	size_t coins() const;

	//void update() const;

	void die();

	void interaction(GameObject* go);

	//friend class Bullet;
};