#include "LifeObject.h"

#include "World.h"
#include "DisplayManager.h"

#include <iostream>


using namespace std;
using namespace World;


LifeObject::LifeObject(int position, char shape, int hp, int max_hp) 
	: GameObject { position, shape }, hp { hp }, max_hp { max_hp } {
	
}


void LifeObject::getDamage(int dmg) {
	hp -= dmg;
	if(hp <= 0) {
		hp = 0;
		die();
	}
}

void LifeObject::die() {
	//gotoxy(position, ground_y);
	//cout << ground;

	world[position] = nullptr;
	position = -1;
}


int LifeObject::maxHP() const {
	return max_hp;
}

int LifeObject::currentHP() const {
	return hp;
}


void LifeObject::update() {
	if(hp > 0) {
		GameObject::update();
	}
}