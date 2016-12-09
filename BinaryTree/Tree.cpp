#include "Tree.h"

bool Tree::insertHelper(pNode node, int value)
{
	if (node->getValue() < value)
	{
		if (node->getLeft() != nullptr)
			return insertHelper(node->getLeft(), value);
		else
			return node->setLeft(std::make_shared<Node>(new Node(value)));
	}
	else
	{
		if (node->getRight() != nullptr)
			return insertHelper(node->getRight(), value);
		else
			return node->setRight(std::make_shared<Node>(new Node(value)));
	}
}
bool Tree::insert(int value)
{
	if (root == nullptr)
	{
		root = std::make_shared<Node>(new Node(value));
		return true;
	}
	else
	{
		return insertHelper(root, value);
	}
}

bool Tree::containsHelper(pNode node, int value)
{
	if (node == nullptr) return false;
	if (node->getValue() == value) return true;
	else if (node->getValue() < value) containsHelper(node->getLeft(), value);
	else containsHelper(node->getRight(), value);
}
bool Tree::contains(int value)
{
	return containsHelper(root, value);
}

int Tree::removeHelper(pNode node, int value)
{
	if (node == nullptr) return -1;
	else if (node->getValue == value)
	{
		node
	}
}
int Tree::remove(int value)
{
	//Remove root is hard
	return removeHelper(root, value);
}

int Tree::getMax() const
{
	//Go right until you can't anymore?
	pNode temp = root;
	//Get most right guy
	while (temp->getRight()) temp = temp->getRight();
	return temp->getValue();
}

int Tree::getMin() const
{
	//Go right until you can't anymore?
	pNode temp = root;
	//Get most right guy
	while (temp->getLeft()) temp = temp->getLeft();
	return temp->getValue();
}

bool Tree::traversePreOrder()
{

}

bool Tree::traverseInOrder()
{

}

bool Tree::traversePostOrder()
{

}