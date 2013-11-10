#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
	public:
		void IterateGame();
		GameManager();
		bool isRunning();
	private:
		int playerTurn = 1;
		int turnCount = 1;
		int nextBoard = 0;
		Board boards[9];
		bool gameRunning = true;

};

#endif