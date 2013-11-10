#include "board.h"

Board::Board() {
	for (int i = 0; i < 9; i++) {
		spaces[i] = 0;
	}
	winner = 0;
}

int Board::hasWinner() {
	return winner;
}

void Board::findWinner() {
	if (spaces[0] == spaces[1] && spaces[1] == spaces[2])
		winner = spaces[0];
	else if (spaces[3] == spaces[4] && spaces[4] == spaces[5])
		winner = spaces[3];
	else if (spaces[6] == spaces[7] && spaces[7] == spaces[8])
		winner = spaces[6];
	else if (spaces[6] == spaces[3] && spaces[3] == spaces[0])
		winner = spaces[6];
	else if (spaces[7] == spaces[4] && spaces[4] == spaces[1])
		winner = spaces[7];
	else if (spaces[8] == spaces[5] && spaces[5] == spaces[2])
		winner = spaces[8];	
	else if (spaces[0] == spaces[4] && spaces[4] == spaces[8])
		winner = spaces[0];
	else if (spaces[6] == spaces[4] && spaces[4] == spaces[2])
		winner = spaces[6];
}

void Board::move(int space, int player) {
	spaces[space] = player;
	if (winner == 0) findWinner();
}

int Board::getSpace(int space) {
	return spaces[space];
}

bool Board::isFull() {
	for (int i = 0; i < 9; i++) {
		if (spaces[i] == 0)
			return false;
	}
	return true;
}