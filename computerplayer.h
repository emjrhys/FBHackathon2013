#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "board.h"

class ComputerPlayer {
	public:
		ComputerPlayer(int l);
		int takeTurn(Board boards[], int nextBoard);
		int pickBoard(Board boards[]);
		

	private:
		int canWin(Board b);
		int level;
		
};

#endif