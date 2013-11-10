#include <iostream>

#include "gamemanager.h"
#include "board.h"
#include "computerplayer.h"

using namespace std;

int main(int argc, char ** argv) {
	GameManager * game;
	bool usingAI = (argc > 1 && argv[1][0] == 'a' && argv[1][1] == 'i');
	if (usingAI) {
		ComputerPlayer * ai = new ComputerPlayer();
		game = new GameManager(ai);
		cout << "Playing with an AI" << endl;
	}
	else game = new GameManager();

	cout << endl << "Type anything and press <ENTER> to begin, or type \"rules\" to learn how to play." << endl;
	string in;
	string r = "rules";

	cin >> in;
	if (in == r) {
		cout << endl << 
		"How to Play: Tic-Tac-Two looks a lot like traditional Tic-Tac-Toe. \nYou have the same board, and you can win the same way. But instead of just \nchoosing squares, players must win them by playing another game of \nTic-Tac-Toe inside that square. However, when a square is picked, \nthe next player takes his turn in the corresponding board on the \nlarger grid. For example, if Player 1 puts his X in the top left of \nthe current board, Player 2 must play on the top left board. If one player \nsends the other to a full board, that player gets to pick the next board. \nThe game is over when a player wins three boards in a row. If the game ends \nin a tie, the player with more boards wins. Good luck!" << endl;
	}
	while (game->isRunning()) {
		game->iterateGame();
	}
}