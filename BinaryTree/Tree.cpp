#include "Tree.h"

pNode Tree::sharedPointerHelper(Node* n)
{
	return std::shared_ptr<Node>(n);
}

bool Tree::insertHelper(pNode node, int value)
{
	if (node->getValue() > value)
	{
		if (node->hasLeft())
			return insertHelper(node->getLeft(), value);
		else
			return node->setLeft(sharedPointerHelper(new Node(value)));
	}
	else
	{
		if (node->hasRight())
			return insertHelper(node->getRight(), value);
		else
			return node->setRight(sharedPointerHelper(new Node(value)));
	}
}
bool Tree::insert(int value)
{
	if (root == nullptr)
	{
		root = sharedPointerHelper(new Node(value));
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
	else if (node->getValue() > value) return containsHelper(node->getLeft(), value);
	else return containsHelper(node->getRight(), value);
}
bool Tree::contains(int value)
{
	return containsHelper(root, value);
}


int Tree::removeHelper(pNode node, int value)
{
	if (node == nullptr)
	{
		std::cout << "Node not found!" << std::endl;
		return -1;
	}
	else if (node->getValue() > value && node->getLeft() != nullptr)
	{
		pNode leftNode = node->getLeft();
		if (leftNode->getValue() == value)
		{
			if (leftNode->hasRight())
			{
				node->setLeft(leftNode->getRight());
				return value;
			}
			else if (leftNode->hasLeft())
			{
				node->setLeft(leftNode->getLeft());
				return value;
			}
			else
			{
				node->setLeft(nullptr);
				return value;
			}
		}
		else
		{
			return removeHelper(leftNode, value);
		}
	}
	else if (node->hasRight())
	{
		pNode rightNode = node->getRight();
		if (rightNode->getValue() == value)
		{
			if (rightNode->hasRight())
			{
				node->setRight(rightNode->getRight());
				return value;
			}
			else if (rightNode->hasLeft())
			{
				node->setRight(rightNode->getLeft());
				return value;
			}
			else
			{
				node->setRight(nullptr);
				return value;
			}
		}
		else
		{
			return removeHelper(rightNode, value);
		}
	}
	else
	{
		std::cout << "Node not found!" << std::endl;
		return -1;
	}
}
int Tree::remove(int value)
{
	if (root == nullptr) return INT_MIN;
	if (root->getValue() == value)
	{
		if (root->hasRight())
		{
			int newValue = remove(getMin(root->getRight()));
			root->setValue(newValue);
			return value;
		}
		else if (root->hasLeft())
		{
			int newValue = remove(getMax(root->getLeft()));
			root->setValue(newValue);
			return value;
		}
		else
		{
			root->setValue(value);
			return value;
		}
	}
	else return removeHelper(root, value);
}

int Tree::getMax() const
{
	pNode temp = root;
	if (temp == nullptr) return INT_MIN;
	//Get most right guy
	while (temp->getRight()) temp = temp->getRight();
	return temp->getValue();
}

int Tree::getMin() const
{
	pNode temp = root;
	if (temp == nullptr) return INT_MIN;
	//Get most left guy
	while (temp->getLeft()) temp = temp->getLeft();
	return temp->getValue();
}

int Tree::getMax(pNode node) const
{
	//Get most right guy 
	while (node->getRight()) node = node->getRight();
	return node->getValue();
}

int Tree::getMin(pNode node) const
{
	//Get most left guy
	while (node->getLeft()) node = node->getLeft();
	return node->getValue();
}

void Tree::preOrderHelper(pNode node)
{
	if (node == nullptr) return;
	std::cout << node->getValue() << " ";
	preOrderHelper(node->getLeft());
	preOrderHelper(node->getRight());
}
void Tree::traversePreOrder()
{
	std::cout << "PreOrder: ";
	return preOrderHelper(root);
}

void Tree::inOrderHelper(pNode node)
{
	if (node == nullptr) return;
	inOrderHelper(node->getLeft());
	std::cout << node->getValue() << " ";
	inOrderHelper(node->getRight());
}
void Tree::traverseInOrder()
{
	std::cout << "InOrder: ";
	return inOrderHelper(root);
}

void Tree::postOrderHelper(pNode node)
{
	if (node == nullptr) return;
	postOrderHelper(node->getLeft());
	postOrderHelper(node->getRight());
	std::cout << node->getValue() << " ";
}
void Tree::traversePostOrder()
{
	std::cout << "PostOrder: ";
	return postOrderHelper(root);
}