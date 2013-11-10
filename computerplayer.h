#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "board.h"

class ComputerPlayer {
	public:
		int takeTurn(Board boards[], int nextBoard);
		

	private:
		int canWin(Board b);
		
};

#endif