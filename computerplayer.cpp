#include "computerplayer.h"

ComputerPlayer::ComputerPlayer(int l) {
	level = l;
}

int ComputerPlayer::takeTurn(Board boards[], int nextBoard) {
	if (level == 1) {
		if (boards[nextBoard].hasWinner() != 0) {
			for (int i = 8; i >= 0; i--) {
				if (boards[nextBoard].getSpace(i) == 0) return i;
			}
		}
		int c = canWin(boards[nextBoard]);
		if (c != -1) return c;
		int priority[] = {6, 2, 0, 8, 4, 3, 5, 7, 1};
		for (int i = 0; i < 9; i++) {
			if (boards[nextBoard].getSpace(priority[i]) == 0)
				return priority[i];
		}
		return 0;
	}
	if (level == 2) {
		if (boards[nextBoard].hasWinner() != 0) {
			for (int i = 8; i >= 0; i--) {
				if (boards[nextBoard].getSpace(i) == 0) return i;
			}
		}
		int max = -10000;
		int maxIndex = 0;
		for (int i = 0, h = boards[nextBoard].gt.root->children.size(); i < h; i++) {
			int s = boards[nextBoard].gt.root->children[i]->score;
			if (s > max) {
				max = s;
				maxIndex = i;
			}
		}
		return boards[nextBoard].gt.root->children[maxIndex]->move;
	}
	return 3;
}

int ComputerPlayer::pickBoard(Board boards[]) {
	int priority[] = {6, 2, 0, 8, 4, 3, 5, 7, 1};
	for (int i = 0; i < 9; i++) {
		if (!boards[i].isFull())
			return priority[i];
	}
	return 0;
}

int ComputerPlayer::canWin(Board b) {
	for (int i = 0; i < 3; i++) {
		if (b.getSpace(i*3) == 2 && b.getSpace(i*3+1) == 2 && b.getSpace(i*3+2) == 0) return i*3+2;
		if (b.getSpace(i*3) == 2 && b.getSpace(i*3+2) == 2 && b.getSpace(i*3+1) == 0) return i*3+1;
		if (b.getSpace(i*3+1) == 2 && b.getSpace(i*3+2) == 2 && b.getSpace(i*3) == 0) return i*3;
		if (b.getSpace(i) == 2 && b.getSpace(3+i) == 2 && b.getSpace(6+i) == 0) return 6+i;
		if (b.getSpace(i) == 2 && b.getSpace(6+i) == 2 && b.getSpace(3+i) == 0) return 3+i;
		if (b.getSpace(3+i) == 2 && b.getSpace(6+i) == 2 && b.getSpace(i) == 0) return i;
	}
	if (b.getSpace(0) == 2 && b.getSpace(4) == 2 && b.getSpace(8) == 0) return 8;
	if (b.getSpace(4) == 2 && b.getSpace(8) == 2 && b.getSpace(0) == 0) return 0;
	if (b.getSpace(4) == 2 && b.getSpace(2) == 2 && b.getSpace(6) == 0) return 6;
	if (b.getSpace(6) == 2 && b.getSpace(4) == 2 && b.getSpace(2) == 0) return 2;
	if (b.getSpace(6) == 2 && b.getSpace(2) == 2 && b.getSpace(4) == 0) return 4;
	if (b.getSpace(0) == 2 && b.getSpace(8) == 2 && b.getSpace(4) == 0) return 4;
	return -1;
}