#ifndef BOARD_H
#define BOARD_H

class Board {
	public:
		void move(int space, int player);
		int hasWinner();
		void findWinner();
		int getSpace(int space);
		Board();

	private:
		int spaces[9];
		int winner;
};

#endif