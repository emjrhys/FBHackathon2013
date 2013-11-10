#ifndef GAMETREE_H
#define GAMETREE_H

#include "board.h"
#include <vector>

class GameTree {
	public:
		GameTree();
		

	private:
		void buildTree();
		class GameTreeNode {
			public:
				GameTreeNode(int arr[], int playerTurn);
				vector<GameTreeNode *> children;

			private:
				int spaces[9];
				int winner;
				int playerTurn;
		};

		GameTreeNode * root;
};

#endif