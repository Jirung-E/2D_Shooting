#pragma once

#include "GameObject.h"

class Bullet : public GameObject {
	const static char bullet_r = '>';
	const static char bullet_l = '<';

	bool isfired;
	int atk_power;

public:
	Bullet();

	void destroy();
	void attack(GameObject* go);
	void move_l();
	void move_r();
	void go();

	void interaction(GameObject* go);

	friend class Player;
};