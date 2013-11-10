#ifndef GAMETREE_H
#define GAMETREE_H

#include <vector>

class GameTree {
	public:
		GameTree();
		void move(int space, int player);

		class GameTreeNode {
			public:
				GameTreeNode(int arr[], int turn, int m);
				std::vector<GameTreeNode *> children;

				int hasWinner();
				bool isFull();

				void printBoard();

				int spaces[9];
				int winner;
				int playerTurn;
				int move;
				int score;
		};
		GameTreeNode * root;

		void printTree();
		void printTree(GameTreeNode * subRoot);
		

	private:

		void buildTree();
		void buildTree(GameTreeNode * subRoot);

		
};

#endif