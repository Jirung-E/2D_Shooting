#include "Coin.h"

#include "World.h"
#include "DisplayManager.h"

#include "Player.h"

#include <iostream>


using namespace std;
using namespace World;


Coin::Coin(int position) : GameObject { position, coin } {
	shape = coin;

	//world[position] = this;
	//gotoxy(position, ground_y);
	//cout << shape;
}


void Coin::destroy() {
	//gotoxy(position, ground_y);
	//cout << ground;

	position = -1;
	world[position] = nullptr;
}


void Coin::interaction(GameObject* go) {

}