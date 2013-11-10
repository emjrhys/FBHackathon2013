#ifndef BOARD_H
#define BOARD_H

class Board {
	public:
		/**
		 * The default constructor.
		 * Initializes all board spaces to 0.
		 */
		Board();

		/**
		 * Changes the value at a specific space to the player number.
		 */
		void move(int space, int player);

		/**
		 * Check whether a winner has been found, and return the player number.
		 */
		int hasWinner();
		
		/**
		 * Get the value at a specific location.
		 */
		int getSpace(int space);

		/**
		 * Checks if the board is full.
		 */
		bool isFull();

	private:
		/**
		 * Checks all combinations and updates the winner.
		 */
		void findWinner();

		/**
		 * The array of spaces
		 */
		int spaces[9];

		/**
		 * The winner. Default is zero.
		 */
		int winner;
};

#endif