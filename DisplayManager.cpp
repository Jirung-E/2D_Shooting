#include "DisplayManager.h"

#include <iostream>
#include <chrono>

#include "World.h"

#include "Player.h"
extern Player player;


// ------------------------------------------------------------------------
void gotoxy(SHORT x, SHORT y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// ------------------------------------------------------------------------


using namespace std;
using namespace World;


auto start_time = std::chrono::system_clock::now();


void DisplayManager::SeparateLine() {
	cout << "--------------------------------------------------------------------------------------" << endl;
}

void DisplayManager::PlayTime() {
	chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - start_time;
	//cout << "PlayTime : " << elapsed_seconds.count() << "s" << endl;
	printf("PlayTime : %.1lfs\n", elapsed_seconds.count());
}



using namespace DisplayManager;

void GameScreen::Default() {
	gotoxy(0, 0);

	SeparateLine();
	cout << endl;
	SeparateLine();
	cout << endl
		<< endl;
	SeparateLine();

	gotoxy(0, ground_y);
	for(int i=0; i<World::size; ++i) {
		cout << ground;
	}
}

void GameScreen::Update() {
	gotoxy(0, 1);
	PlayTime();

	gotoxy(0, 3);
	cout << "COIN" << '\t' << player.coins() << endl;
	//cout << " HP " << '\t' << player.currentHP() << " / " << player.maxHP();
	printf(" HP \t%d / %d  ", player.currentHP(), player.maxHP());
}