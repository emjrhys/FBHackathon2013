#include <iostream>

#include "gamemanager.h"
#include "board.h"
#include "computerplayer.h"

using namespace std;

int main(int argc, char ** argv) {
	GameManager * game;
	bool usingAI = (argc > 1 && argv[1][0] == 'a' && argv[1][1] == 'i');
	if (usingAI) {
		ComputerPlayer * ai = new ComputerPlayer();
		game = new GameManager(ai);
		cout << "Playing with an AI" << endl;
	}
	else game = new GameManager();
	while (game->isRunning()) {
		game->iterateGame();
	}
}
