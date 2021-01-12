#pragma once

#include "GameObject.h"

//#include "Monster.h"


class Coin : public GameObject {
	const char coin = 'C';

public:
	Coin(int position);
	//~Coin();

	void destroy();

	void interaction(GameObject* go) override final;

	friend class Monster;
};