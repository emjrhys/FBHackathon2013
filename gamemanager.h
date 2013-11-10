#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "board.h"
#include "computerplayer.h"

#include <iostream>

class GameManager {
	public:
		GameManager();
		GameManager(ComputerPlayer * comp);
		void iterateGame();
		bool isRunning();
		bool hasWinner();
		void findWinner();
		void printGame();
		void printKey();

	private:
		int playerTurn;
		int nextBoard;
		Board boards[9];
		bool gameRunning;
		int winner;
		bool usingAI;

		ComputerPlayer * ai;

};

#endif