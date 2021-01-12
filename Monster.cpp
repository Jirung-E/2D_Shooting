#include "Monster.h"

#include "World.h"
#include "DisplayManager.h"

#include "Player.h"
#include "Bullet.h"
#include "Coin.h"

#include <iostream>
//#include <chrono>


using namespace std;
using namespace World;


Monster::Monster() : LifeObject { -1, monster, 10, 10 }, atk_power { 2 },
	spawned { false }, spawn_point { World::min_x }, move_speed { 3.0f },
	last_move { chrono::system_clock::now() } {
	shape = monster;
	coin = new Coin { -1 };
}

Monster::Monster(int position) : LifeObject { position, monster, 10, 10 }, atk_power { 2 },
	spawned { false }, spawn_point { position }, move_speed { 3.0f },
	last_move { chrono::system_clock::now() } {
	shape = monster;
	coin = new Coin { -1 };
}

Monster::~Monster() {
	delete coin;
}



float Monster::moveSpeed() const {
	return move_speed;
}

void Monster::attack(GameObject* go) {
	if(dynamic_cast<Player*>(go)) {
		dynamic_cast<Player*>(go)->getDamage(atk_power);

		if(spawn_point == World::min_x) {
			position--;
		}
		else if(spawn_point == World::max_x) {
			position++;
		}
	}
}

void Monster::go() {
	if(spawned) {
		if(world[position] != nullptr) {
			interaction(world[position]);
			if(position < World::min_x) {	// destroyed
				return;
			}
		}

		// <canMove?>
		const auto move_rate = 1s / move_speed;
		auto now = std::chrono::system_clock::now();

		if(now - last_move < move_rate) {
			return;
		}

		last_move = chrono::system_clock::now();
		// </canMove?>

		if(spawn_point == World::min_x) {
			move_r();
		}
		else if(spawn_point == World::max_x) {
			move_l();
		}
	}
}

int Monster::random_spawn_point() const {
	if(World::random_point(World::dre)% 2 == 0) {
		return World::min_x;
	}
	
	return World::max_x;
}

void Monster::spawn() {
	spawn_point = World::random_point(World::dre)% 2 == 0 ? World::min_x : World::max_x;
	spawned = true;
	position = spawn_point;
}


void Monster::interaction(GameObject* go) {
	if(hp > 0) {
		attack(go);
	}

	//if(dynamic_cast<Monster*>(go)) {
	//	if(spawn_point == World::min_x) {
	//		position--;
	//	}
	//	else if(spawn_point == World::max_x) {
	//		position++;
	//	}
	//}
}

void Monster::getDamage(int dmg) {
	hp -= dmg;
	if(hp <= 0) {
		hp = 0;
		die();
	}
}

void Monster::die() {
	coin->position = position;

	LifeObject::die();
	spawned = false;
}


void Monster::update() {
	LifeObject::update();
	if(hp <= 0) {
		coin->update();
	}
}