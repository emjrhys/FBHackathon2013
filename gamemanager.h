#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
	public:
		void IterateGame();
	private:
		int playerTurn = 1;
		int turnCount = 1;

};

#endif