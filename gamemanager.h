#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"

#include <iostream>

class GameManager {
	public:
		void iterateGame();
		GameManager();
		bool isRunning();
		bool hasWinner();
		void findWinner();
		void printGame();
		void printKey();

	private:
		int playerTurn;
		int turnCount;
		int nextBoard;
		Board boards[9];
		bool gameRunning;
		int winner;

};

#endif