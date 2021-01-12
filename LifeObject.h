#pragma once

#include "GameObject.h"

class LifeObject : public GameObject {
protected:
	int hp;
	const int max_hp;

public:
	LifeObject(int position, char shape, int hp, int max_hp);

	void getDamage(int dmg);
	void die();

	int maxHP() const;
	int currentHP() const;

	void update();
};