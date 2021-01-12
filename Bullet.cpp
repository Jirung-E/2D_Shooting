#include "Bullet.h"

#include "World.h"
#include "DisplayManager.h"

#include "Monster.h"

#include <iostream>


using namespace std;
using namespace World;


Bullet::Bullet() : GameObject { -1, 'o' }, isfired { false }, atk_power { 5 } {

}


void Bullet::destroy() {
	//gotoxy(position, ground_y);
	//cout << ground;

	isfired = false;
	position = -1;
}

void Bullet::attack(GameObject* go) {
	if(Monster* m = dynamic_cast<Monster*>(go)) {
		gotoxy(position, ground_y);
		cout << ground;
		world[position] = nullptr;

		m->getDamage(atk_power);

		destroy();
	}
}

void Bullet::move_l() {
	position--;

	if(position < World::min_x) {
		destroy();
		return;
	}

	gotoxy(position, ground_y);
	cout << shape;
}

void Bullet::move_r() {
	position++;

	if(position > World::max_x) {
		destroy();
		return;
	}

	gotoxy(position, ground_y);
	cout << shape;
}

void Bullet::go() {
	if(isfired) {
		if(position > World::max_x || position < World::min_x) {
			destroy();
			gotoxy(World::max_x + 1, ground_y);
			cout << ' ';
			return;
		}

		if(world[position] != nullptr) {
			interaction(world[position]);
			if(position < World::min_x) {	// destroyed
				return;
			}
		}

		gotoxy(position, ground_y);
		cout << ground;
		world[position] = nullptr;

		if(shape == bullet_r) {
			move_r();
		}
		else if(shape == bullet_l) {
			move_l();
		}
	}
}


void Bullet::interaction(GameObject* go) {
	attack(go);
}