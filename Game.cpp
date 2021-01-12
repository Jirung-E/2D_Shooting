#pragma warning(disable : 4996)

#include "Game.h"
#include "World.h"
#include "DisplayManager.h"
#include "Player.h"
//#include "Coin.h"
#include "Monster.h"

#include <iostream>
#include <conio.h>

#include <thread>
#include <chrono>


using namespace std;
using namespace World;
using namespace DisplayManager;


// Start
Player player;
Monster monster[80];


void Game::Start() {
	GameScreen::Default();
	player.update();
}

bool Game::Update() {
	for(Bullet& e : player.bullet) {
		e.go();
		//e.update();
	}
	for(Monster& e : monster) {
		e.go();
	}
	
	char key = '\0';
	if(kbhit()) {
		key = static_cast<char>(_getwch());
		fflush(stdin);
	}

	switch(key) {
		case 'a':
			player.move_l();
			break;
		case 'd':
			player.move_r();
			break;
		case 's':
			player.shoot();
			break;
		case 'q':
		case 'e':
			return false;
	}

	for(Bullet& e : player.bullet) {
		e.update();
	}
	for(Monster& e : monster) {
		e.update();
	}
	player.update();
	
	GameScreen::Update();

	if(player.currentHP() <= 0) {
		player.die();
		return false;
	}

	return true;
}



void Game::Play() {
	Game::Start();

	while(true) {
		static int monster_cnt = 0;

		if(monster_cnt < 80) {
			const auto spawn_rate = 1s;
			static auto last_spawn = chrono::system_clock::now();
			auto now = std::chrono::system_clock::now();

			if(now - last_spawn >= spawn_rate) {
				monster[monster_cnt].spawn();
				monster_cnt++;

				last_spawn = chrono::system_clock::now();
			}
		}

		if(Update() == false) {
			break;
		}

		this_thread::sleep_for(chrono::milliseconds(1000 / fps));
	}

	gotoxy(0, ground_y + 5);
	cout << "게임을 종료합니다!" << endl;
}