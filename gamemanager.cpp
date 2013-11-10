#include "gamemanager.h"
#include <iostream>

using namespace std;

GameManager::GameManager() {
	playerTurn = 1;
	nextBoard = 0;
	gameRunning = true;
	winner = 0;
	ai = NULL;
	usingAI = false;
}

GameManager::GameManager(ComputerPlayer * comp) {
	playerTurn = 1;
	nextBoard = 0;
	gameRunning = true;
	winner = 0;
	ai = comp;
	usingAI = true;
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
		printGame();
		cout << "Player " << winner << " wins!" << endl;
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

	string midLinePlain = "-+-+-";
	string midLineDivider = " \033[1;31m|\033[0m ";

	string midLineP1 = "\033[1;36m-+-+-\033[0m";
	string midLineP2 = "\033[1;35m-+-+-\033[0m";

	string blankLine = "\033[1;31m      |       |      \033[0m";
	string line = "\033[1;31m------+-------+------\033[0m";
	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arr[i][j] = boards[(6+(j/3)-(i/3*3))].getSpace(6+(j%3)-((i%3)*3));
			if (arr[i][j] == 0) {
				if (nextBoard-1 == (6+(j/3)-(i/3*3))) {
					if (playerTurn == 1)
						cout << "\033[1;36m";
					else
						cout << "\033[1;35m";
					cout << (6+(j%3)-((i%3)*3))+1;
					cout << "\033[0m";
				}
				else cout << " ";
			}
			else if (arr[i][j] == 1) cout << "X";
			else if (arr[i][j] == 2) cout << "O";

			if (j == 2 || j == 5) {
				
				cout << " \033[1;31m|\033[0m ";
			}
			else if (j != 8) {
				if (boards[(6+(j/3)-(i/3*3))].hasWinner() == 1)
					cout << "\033[1;36m";
				else if (boards[(6+(j/3)-(i/3*3))].hasWinner() == 2)
					cout << "\033[1;35m";
				cout << "|\033[0m";
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
				if (boards[6].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[6].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << midLineDivider;
				if (boards[7].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[7].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << midLineDivider;
				if (boards[8].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[8].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << endl;
			}
			else if (i/3 == 1) {
				if (boards[3].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[3].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << midLineDivider;
				if (boards[4].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[4].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << midLineDivider;
				if (boards[5].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[5].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << endl;
			}
			else if (i/3 == 2) {
				if (boards[0].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[0].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << midLineDivider;
				if (boards[1].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[1].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << midLineDivider;
				if (boards[2].hasWinner() == 1)
					cout << midLineP1;
				else if (boards[2].hasWinner() == 2)
					cout << midLineP2;
				else cout << midLinePlain;
				cout << endl;
			}
		}
	}	
	cout << endl;
}

void GameManager::printKey() {
	if (playerTurn == 1)
		cout << "\033[1;36m";
	else cout << "\033[1;35m";
	cout << endl << "7|8|9" << endl << "-+-+-" << 
	endl << "4|5|6" << endl << "-+-+-" <<
	endl << "1|2|3" << endl << endl;
	cout << "\033[0m";
}

void GameManager::iterateGame() {
	if (nextBoard == 0 && (!usingAI || playerTurn == 1)) {
		printKey();
		printGame();
		int next = 10;
		while (next > 9 || next < 1 || boards[next-1].isFull()) {
			cout << "Player " << playerTurn << ": Choose a board to play on (1-9): ";
			cin >> next;
		}
		nextBoard = next;
	}
	else if (nextBoard == 0) {
		cout << "Computer's turn to pick a board.";
		int next = ai->pickBoard(boards);
		next += 1;
		cout << "Computer picked " << next << "." << endl;
		nextBoard = next;
	}

	int space;
	if (!usingAI || playerTurn == 1) {
		printGame();

		space = 10;
		cout << "Player " << playerTurn << "'s Turn!" << endl; 
		cout << "You are playing on board " << nextBoard << "." << endl;
		while (space > 9 || space < 1) {
			cout << "Choose a space to play on (1-9): ";
			cin >> space;
			if (boards[nextBoard-1].getSpace(space-1) != 0) {
				cout << "That space is already taken. Try again." << endl;
				space = 10;
			}
		}
	}
	else {
		cout << "Computer's turn." << endl;
		space = ai->takeTurn(boards, nextBoard-1);
		cout << "Computer went in " << space+1 << "." << endl;
		space+=1;
	}
	boards[nextBoard-1].move(space-1, playerTurn);
	if (boards[space-1].isFull()) 
		nextBoard = 0;
	else nextBoard = space;
	playerTurn = (playerTurn%2)+1;
}

