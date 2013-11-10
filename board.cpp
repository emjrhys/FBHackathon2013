#include "board.h"

Board::Board() {
	for (int i = 0; i < 9; i++) {
		spaces[i] = 0;
	}
}

int Board::hasWinner() {
	
}