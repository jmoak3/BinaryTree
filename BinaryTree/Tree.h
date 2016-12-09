#pragma once
#include "Util.h"
#include "Node.h"

class Tree {
public:
	Tree() : root(new Node(0)) {}
	Tree(int value) : root(new Node(value)) {}
	Tree(pNode newRoot) : root(newRoot) {}

	int getMax() const;
	int getMin() const;

	int getMax(pNode node) const;
	int getMin(pNode node) const;

	void traversePreOrder();
	void traverseInOrder();
	void traversePostOrder();

	bool insert(int value);
	bool contains(int value);
	int remove(int value);

private:
	pNode root;

	bool insertHelper(pNode node, int value);
	bool containsHelper(pNode node, int value);
	int removeHelper(pNode node, int value);

	void preOrderHelper(pNode node);
	void inOrderHelper(pNode node);
	void postOrderHelper(pNode node);


	pNode sharedPointerHelper(Node* n);
};