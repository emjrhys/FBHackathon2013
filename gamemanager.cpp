#include "gamemanager.h"
#include <iostream>

using namespace std;

GameManager::GameManager() {
	playerTurn = 1;
	turnCount = 1;
	nextBoard = 0;
	gameRunning = true;
	winner = 0;
}

bool GameManager::isRunning() {
	if (hasWinner() != 0) {
		gameRunning = false;
	}
	return gameRunning;
}

bool GameManager::hasWinner() {
	findWinner();
	if (winner != 0) {
		cout << "Player " << winner << " wins!" << cout;
		return true;
	}
	else return false;
}

void GameManager::findWinner() {
	if (boards[0].hasWinner() == boards[1].hasWinner() && boards[1].hasWinner() == boards[2].hasWinner())
		winner = boards[0].hasWinner();
	else if (boards[3].hasWinner() == boards[4].hasWinner() && boards[4].hasWinner() == boards[5].hasWinner())
		winner = boards[3].hasWinner();
	else if (boards[6].hasWinner() == boards[7].hasWinner() && boards[7].hasWinner() == boards[8].hasWinner())
		winner = boards[6].hasWinner();
	else if (boards[6].hasWinner() == boards[3].hasWinner() && boards[3].hasWinner() == boards[0].hasWinner())
		winner = boards[6].hasWinner();
	else if (boards[7].hasWinner() == boards[4].hasWinner() && boards[4].hasWinner() == boards[1].hasWinner())
		winner = boards[7].hasWinner();
	else if (boards[8].hasWinner() == boards[5].hasWinner() && boards[5].hasWinner() == boards[2].hasWinner())
		winner = boards[8].hasWinner();
	else if (boards[0].hasWinner() == boards[4].hasWinner() && boards[4].hasWinner() == boards[8].hasWinner())
		winner = boards[0].hasWinner();
	else if (boards[6].hasWinner() == boards[4].hasWinner() && boards[4].hasWinner() == boards[2].hasWinner())
		winner = boards[6].hasWinner();
}

void GameManager::printGame() {
	cout << endl;

	string midLine = "-+-+- \033[1;31m|\033[0m -+-+- \033[1;31m|\033[0m -+-+-";
	string midLineLeft = "\033[1;34m-+-+-\033[0m \033[1;31m|\033[0m -+-+- \033[1;31m|\033[0m -+-+-";
	string midLineMid = "-+-+- \033[1;31m|\033[0m \033[1;34m-+-+-\033[0m \033[1;31m|\033[0m -+-+-";
	string midLineRight = "-+-+- \033[1;31m|\033[0m -+-+- \033[1;31m|\033[0m \033[1;34m-+-+-\033[0m";

	string blankLine = "\033[1;31m      |       |      \033[0m";
	string line = "\033[1;31m------+-------+------\033[0m";
	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arr[i][j] = boards[(6+(j/3)-(i/3*3))].getSpace(6+(j%3)-((i%3)*3));
			if ((6+(j/3)-(i/3*3)) == nextBoard-1) {
				cout << "\033[1;34m";
			}
			if (arr[i][j] == 0) cout << " ";
			else if (arr[i][j] == 1) cout << "X";
			else if (arr[i][j] == 2) cout << "O";

			if (j == 2 || j == 5) {
				cout << " \033[1;31m|\033[0m ";
			}
			else if (j != 8) {
				cout << "|";
			}
			if ((6+(j/3)-(i/3*3)) == nextBoard-1) {
				cout << "\033[0m";
			}
		}
		cout << endl;

		if (i == 2 || i == 5) {
			cout << blankLine << endl;
			cout << line << endl;
			cout << blankLine << endl;
		}
		else if (i != 8) {
			if (i/3 == 0) {
				if (nextBoard == 7) {
					cout << midLineLeft << endl;
				}
				else if (nextBoard == 8) {
					cout << midLineMid << endl;
				}
				else if (nextBoard == 9) {
					cout << midLineRight << endl;
				}
				else 
					cout << midLine << endl;
			}
			else if (i/3 == 1) {
				if (nextBoard == 4) {
					cout << midLineLeft << endl;
				}
				else if (nextBoard == 5) {
					cout << midLineMid << endl;
				}
				else if (nextBoard == 6) {
					cout << midLineRight << endl;
				}
				else 
					cout << midLine << endl;
			}
			else if (i/3 == 2) {
				if (nextBoard == 1) {
					cout << midLineLeft << endl;
				}
				else if (nextBoard == 2) {
					cout << midLineMid << endl;
				}
				else if (nextBoard == 3) {
					cout << midLineRight << endl;
				}
				else 
					cout << midLine << endl;
			}
		}
	}	
}

void GameManager::printKey() {
	cout << "\033[1;36m";
	cout << endl << "7|8|9" << endl << "-+-+-" << 
	endl << "4|5|6" << endl << "-+-+-" <<
	endl << "1|2|3" << endl;
	cout << "\033[0m";
}

void GameManager::iterateGame() {
	printKey();
	
	if (nextBoard == 0) {
		int next = 10;
		while (next > 9 || next < 1) {
			cout << "Player " << playerTurn << ": Choose a board to start on (1-9): ";
			cin >> next;
		}
		nextBoard = next;
	}

	printGame();

	int space = 10;
	cout << endl << "Player " << playerTurn << "'s Turn!" << endl;
	cout << "You are playing on board " << nextBoard << endl;
	while (space > 9 || space < 1) {
		cout << "Choose a space to play on (1-9): ";
		cin >> space;
		if (boards[nextBoard-1].getSpace(space-1) != 0) {
			cout << "That space is already taken. Try again." << endl;
			space = 10;
		}
	}
	boards[nextBoard-1].move(space-1, playerTurn);
	nextBoard = space;
	playerTurn = (playerTurn%2)+1;
}

