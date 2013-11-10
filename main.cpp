#include <iostream>

#include "gamemanager.h"
#include "board.h"

using namespace std;

int main() {
	GameManager game;
	while (game.isRunning()) {
		game.iterateGame();
	}
}
