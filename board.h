#ifndef BOARD_H
#define BOARD_H

class Board {
	public:
		void move(int space);
		int hasWinner();
		Board();

	private:
		int spaces[9];
		int winner = 0;
};

#end_if