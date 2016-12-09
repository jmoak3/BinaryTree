#pragma once
#include "Util.h"
#include "Node.h"

class Tree {
public:
	Tree() : root(new Node(0)) {}
	Tree(pNode newRoot) : root(newRoot) {}

	int getMax() const;
	int getMin() const;

	bool traversePreOrder();
	bool traverseInOrder();
	bool traversePostOrder();

	bool insert(int value);
	bool contains(int value);
	int remove(int value);

private:
	pNode root;

	bool insertHelper(pNode node, int value);
	bool containsHelper(pNode node, int value);
	int removeHelper(pNode node, int value);
};