#pragma once

#include <Windows.h>

// ------------------------------------------------------------------------
void gotoxy(SHORT x, SHORT y);
// ------------------------------------------------------------------------


namespace DisplayManager {
	void SeparateLine();

	void PlayTime();

	//void PlayerCoin();
	//void PlayerHP();

	//void GameScreen();
	namespace GameScreen {
		void Default();
		void Update();
	}


}