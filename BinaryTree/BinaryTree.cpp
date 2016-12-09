// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "Util.h"
#include "Tree.h"

int main()
{
	std::cout << "Test" << std::endl;

	std::cout << "Making Binary Tree with root 5" << std::endl;
	Tree tree(5);
	tree.traverseInOrder();
	std::cout << std::endl;

	std::cout << "Adding a node of 4" << std::endl;
	tree.insert(4);
	tree.traverseInOrder();
	std::cout << std::endl;

	std::cout << "Getting Smallest node value (4): " << std::endl;
	std::cout << tree.getMin() << std::endl;

	std::cout << "Adding 1, 7, 8, 3. InOrder should be 1 3 4 5 7 8 " << std::endl;
	tree.insert(1); tree.insert(7); tree.insert(8); tree.insert(3);
	tree.traverseInOrder();
	std::cout << std::endl;

	std::cout << "Getting largest Node (8) " << std::endl;
	std::cout << tree.getMax() << std::endl;

	std::cout << "removing 5. In order: 1 3 4 7 8 " << std::endl;
	if (tree.contains(5)) tree.remove(5);
	tree.traverseInOrder();
	std::cout << std::endl;

	std::cout << "Preorder 7 4 1 3 8 " << std::endl;
	tree.traversePreOrder();
	std::cout << std::endl;

	std::cout << "Removing 1. Preorder 7 4 3 8 " << std::endl;
	if (tree.contains(1)) tree.remove(1);
	tree.traversePreOrder();
	std::cout << std::endl;

	std::cout << "In order 3 4 7 8 " << std::endl;
	tree.traverseInOrder();
	std::cout << std::endl;

	std::cout << "Postorder 3 4 8 7 " << std::endl;
	tree.traversePostOrder();
	std::cout << std::endl;

	std::cout << "Preorder 7 4 3 8 " << std::endl;
	tree.traversePreOrder();
	std::cout << std::endl;

	std::cout << "Adding 5. Postorder 3 5 4 8 7 " << std::endl;
	tree.insert(5);
	tree.traversePostOrder();
	std::cout << std::endl;

	std::cout << "Preorder 7 4 3 5 8" << std::endl;
	tree.traversePreOrder();
	std::cout << std::endl;

	std::cout << "inorder 3 4 5 7 8 " << std::endl;
	tree.traverseInOrder();
	std::cout << std::endl;


	std::cin.get();
    return 0;
}

