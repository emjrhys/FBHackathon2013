#include "gametree.h"

#include <iostream>

using namespace std;

GameTree::GameTree() {
	int spaces[9];
	for (int i = 0; i < 9; i++) spaces[i] = 0;
	root = new GameTreeNode(spaces, 1, -1);
	buildTree();
}

GameTree::GameTreeNode::GameTreeNode(int arr[], int turn, int m) {
	playerTurn = turn;
	move = m;
	for (int i = 0; i < 9; i++) {
		spaces[i] = arr[i];
	}
	winner = 0;
	score = 0;
}

void GameTree::buildTree() {
	buildTree(root);
}

void GameTree::buildTree(GameTreeNode * subRoot) {
	//subRoot->printBoard();
	subRoot->winner = subRoot->hasWinner();
	if (subRoot->winner != 0) {
		//cout << "made it here" << endl;
		if (subRoot->winner == 1) subRoot->score = -1;
		else subRoot->score = 1;
		return;
	}
	if (subRoot->isFull()) {
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (subRoot->spaces[i] == 0) {
			int arr[9];
			for (int j = 0; j < 9; j++) {
				arr[j] = subRoot->spaces[j];
			}

			arr[i] = ((subRoot->playerTurn)%2)+1;
			subRoot->children.push_back(new GameTreeNode(arr, ((subRoot->playerTurn)%2)+1, i));
			arr[i] = subRoot->playerTurn;
			subRoot->children.push_back(new GameTreeNode(arr, subRoot->playerTurn, i));
		}
	}
	for (int i = 0, h = subRoot->children.size(); i < h; i++) {
		buildTree(subRoot->children[i]);
		subRoot->score += subRoot->children[i]->score;
	}
	if (subRoot->children.size() == 0) {
		if (subRoot->winner == 1) subRoot->score = -1;
		else if (subRoot->winner == 2) subRoot->score = 1;
	}
}

int GameTree::GameTreeNode::hasWinner() {
	if (spaces[0] == spaces[1] && spaces[1] == spaces[2])
		return spaces[0];
	else if (spaces[3] == spaces[4] && spaces[4] == spaces[5])
		return spaces[3];
	else if (spaces[6] == spaces[7] && spaces[7] == spaces[8])
		return spaces[6];
	else if (spaces[6] == spaces[3] && spaces[3] == spaces[0])
		return spaces[6];
	else if (spaces[7] == spaces[4] && spaces[4] == spaces[1])
		return spaces[7];
	else if (spaces[8] == spaces[5] && spaces[5] == spaces[2])
		return spaces[8];	
	else if (spaces[0] == spaces[4] && spaces[4] == spaces[8])
		return spaces[0];
	else if (spaces[6] == spaces[4] && spaces[4] == spaces[2])
		return spaces[6];
	else return 0;
}

void GameTree::move(int space, int player) {
	for (int i = 0, h = root->children.size(); i < h; i++) {
		if (root->children[i]->move == space && player) {
			root = root->children[i];
		}
	}
}

void GameTree::printTree() {
	printTree(root);
}

bool GameTree::GameTreeNode::isFull() {
	for (int i = 0; i < 9; i++) {
		if (spaces[i] == 0) return false;
	}
	return true;
}

void GameTree::GameTreeNode::printBoard() {
	string midLinePlain = "-+-+-";
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			cout << spaces[6+j-(k*3)];
			if (k == 0 || k == 1) {
				cout << "|";
			}
		}
		cout << endl;
		if (j != 2) {
			cout << midLinePlain << endl;
		}
	}
	cout << endl;
}

void GameTree::printTree(GameTreeNode * subRoot) {
	
	for (int i = 0, h = subRoot->children.size(); i < h; i++) {
		
		cout << endl;
	}
	cout << "------------------------------------" << endl << endl;
}