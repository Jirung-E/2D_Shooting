#include "GameObject.h"

#include "World.h"
#include "DisplayManager.h"

#include <iostream>


using namespace std;
using namespace World;


GameObject::GameObject(int position, char shape) : position { position }, shape { shape } {
	//world[position] = this;
}


void GameObject::move_l() {
	gotoxy(position, ground_y);
	cout << ground;
	world[position] = nullptr;

	if(position > World::min_x) {
		position--;
		if(world[position] != nullptr) {
			interaction(world[position]);
		}
	}

	//gotoxy(position, ground_y);
	//cout << shape;
	//world[position] = this;
	update();
}

void GameObject::move_r() {
	gotoxy(position, ground_y);
	cout << ground;
	world[position] = nullptr;

	if(position < World::max_x) {
		position++;
		if(world[position] != nullptr) {
			interaction(world[position]);
		}
	}

	//gotoxy(position, ground_y);
	//cout << shape;
	//world[position] = this;
	update();
}


bool GameObject::collisionCheck() const {
	if(position + 1 != ground || position - 1 != ground) {
		return true;
	}

	return false;
}

//void GameObject::interaction(GameObject* go) {
//	
//}



void GameObject::update() {
	if(position < World::min_x || position > World::max_x) {
		return;
	}

	gotoxy(position, ground_y);
	cout << shape;
	world[position] = this;
}