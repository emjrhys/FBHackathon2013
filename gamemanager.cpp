#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager() {
	for (int i = 0; i < 9; i++) {
		boards[i] = new Board();
	}
}

bool GameManager::isRunning() {
	return gameRunning;
}

