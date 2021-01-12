#include "Player.h"

#include "World.h"
#include "DisplayManager.h"

#include "Coin.h"
#include "Monster.h"

#include <iostream>
#include <chrono>


using namespace std;
using namespace World;


Player::Player() : LifeObject { World::size / 2, player_r, 10, 10 }, coin { 0 }, capacity { 80 } {
	//gotoxy(position, ground_y);
	//cout << player_r;
	//gotoxy(0, 0);
	shape = player_r;
}

 
void Player::move_l() {
	shape = player_l;

	GameObject::move_l();
}

void Player::move_r() {
	shape = player_r;

	GameObject::move_r();
}

void Player::getCoin() {
	coin++;
}

void Player::shoot() {
	static size_t fire_cnt = 0;

	const auto fire_rate = 0.5s;	// fire per fire_rate		default : 0.5s
	static auto last_fire = chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();

	if(fire_cnt >= capacity) {
		fire_cnt = 0;
	}

	if(now - last_fire >= fire_rate) {
		if(shape == player_r) {
			bullet[fire_cnt].position = position + 1;
			bullet[fire_cnt].shape = Bullet::bullet_r;
		}
		else if(shape == player_l) {
			bullet[fire_cnt].position = position - 1;
			bullet[fire_cnt].shape = Bullet::bullet_l;
		}

		if(world[bullet[fire_cnt].position] != nullptr) {
			interaction(world[position]);
			if(position < World::min_x) {	// destroyed
				return;
			}
		}

		gotoxy(bullet[fire_cnt].position, ground_y);
		cout << bullet[fire_cnt].shape;

		last_fire = chrono::system_clock::now();
		bullet[fire_cnt].isfired = true;
		fire_cnt++;
	}
}


size_t Player::coins() const {
	return coin;
}


void Player::die() {
	LifeObject::die();
	gotoxy(40, ground_y - 2);
	cout << "You died..";
}



void Player::interaction(GameObject* go) {
	if(Coin* c = dynamic_cast<Coin*>(go)) {
		coin++;
		c->destroy();
	}

	if(Monster* m = dynamic_cast<Monster*>(go)) {
		if(shape == player_r) {
			position--;
		}
		else if(shape == player_l) {
			position++;
		}
	}
}