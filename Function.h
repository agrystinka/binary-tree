#pragma once

#include "Class.h"

using namespace std;

template<typename T>
Tree<T>::Tree() {
	root = NULL;
	count = 0;
}

template<typename T>
Tree<T>::Tree(T data) {
	root = new Node(data, NULL);
	count = 1;
}

template<typename T>
Tree<T>::~Tree()
{
	del(this->root, minimal());
	cout << "Tree was destroyed" << endl;
}

template<typename T>
void Tree<T>::add(T data) {
	this->count++;
	if (root == NULL) {

		root = new Node(data, NULL);
		return;
	}
	else {

		auto tmp = root;
		while (tmp)
		{
			if (data >= tmp->data) {
				if (tmp->right) {
					tmp = tmp->right;
					continue;
				}
				else {
					tmp->right = new Node(data, tmp);
					return;
				}
			}
			else if (data < tmp->data) {
				if (tmp->left) {
					tmp = tmp->left;
					continue;
				}
				else {
					tmp->left = new Node(data, tmp);
					return;
				}
			}
		}

	}

	return;
}

template<typename T>
void Tree<T>::print()
{
	printTree(this->root, "Root", 0);
}

template<typename T>
int Tree<T>::minimal()
{
	return min(this->root);
}

template<typename T>
int Tree<T>::maximal()
{
	return max(this->root);
}

template<typename T>
void Tree<T>::remove(T data)
{
	del(this->root, data);
}

template<typename T>
bool Tree<T>::in(T data)
{
	return inTree(this->root, data);
}

template<typename T>
int Tree<T>::getCounter()
{
	return this->count;
}

template<typename T>
int Tree<T>::height()
{
	return heightOfTree(this->root);
}


template<typename T>
void Tree<T>::printTree(Node * root, const char * dir, int level)
{

	if (root) {
		printf("lvl %d %s = %d\n", level, dir, root->data);
		printTree(root->left, "left", level + 1);
		printTree(root->right, "right", level + 1);
	}

}
template<typename T>
int Tree<T>::min(Node * root)
{
	while (root->left) {
		root = root->left;

	}

	return root->data;

}
template<typename T>
int Tree<T>::max(Node * root)
{
	while (root->right) {
		root = root->right;
	}
	return root->data;
}
template<typename T>
bool Tree<T>::inTree(Node *root, T data)
{
	if (root == NULL) {
		//cout << "Tree is empty" << endl;
		return false;
	}
	if (data == root->data)
	{
		//cout << "There is " << data << endl;
		return true;
	}
	if (data < root->data) {
		return inTree(root->left, data);
	}
	else return inTree(root->right, data);
	//cout << "Tree is empty" << endl;
	return false;
}

template<typename T>
int Tree<T>::heightOfTree(Node * root)
{
	if (root == NULL)
		return 0;
	int left, right;
	if (root->left != NULL) {
		left = heightOfTree(root->left);
	}
	else
		left = -1;
	if (root->right != NULL) {
		right = heightOfTree(root->right);
	}
	else
		right = -1;
	int max = left > right ? left : right;
	return max + 1;

}

void choose() {

	cout << "Switch operation to work" << endl;
	cout << "1 - add number" << endl;
	cout << "2 - Print tree" << endl;
	cout << "3 - delete element from the tree" << endl;
	cout << "4 - Find minimal element" << endl;
	cout << "5 - Find maximal element" << endl;
	cout << "6 - Cout height Of Tree" << endl;
	cout << "7 - Check the item in the tree" << endl;
	cout << "8 - Get Counter" << endl;
	cout << "9 - Random " << endl;
	cout << "10 - Finish work" << endl;

}

void workWithTree(Tree<int> &tree)
{
	choose();
	int operation;

	cin >> operation;

	while (operation != 10) {
		switch (operation)
		{
		case 1:
		{
			int size;
			cout << "Enter count elements that you want to insert" << endl;
			cin >> size;

			int *arr = new int[size];
			int elem;
			for (int i = 0; i < size; i++) {
				cout << "Enter element to insert" << endl;
				cin >> elem;
				arr[i] = elem;
			}

			for (int i = 0; i < size; i++)
			{
				tree.add(arr[i]);
			}
			cout << "Adding elements has been finished" << endl;
			delete arr;
			choose();
			cin >> operation;
			break;

		}

		case 2:
		{
			cout << "\n\t=============\t=============\n" << endl;
			tree.print();

			choose();

			cin >> operation;
			break;
		}

		case 3:
		{
			int number;
			cout << "Enter number to delete" << endl;
			cin >> number;
			tree.remove(number);
			choose();
			cin >> operation;
			break;
		}

		case 4:
		{
			cout << "Minimal element is: " << tree.minimal() << endl;
			choose();
			cin >> operation;
			break;
		}
		case 5:
		{

			cout << "Maximal element is: " << tree.maximal() << endl;
			choose();
			cin >> operation;
			break;
		}

		case 6:
		{
			cout << "Height of tree is: " << tree.height() << endl;
			choose();
			cin >> operation;
			break;
		}

		case 7:
		{
			int elem;
			cin >> elem;
			
			if (tree.in(elem)) {
				cout << "There is " << elem << " in tree" << endl;
			}
			else {
				cout << "There is not " << elem << "in tree" << endl;
			}
			choose();
			cin >> operation;
			break;
		}
		case 8:
		{
			cout << tree.getCounter() << endl;
			choose();
			cin >> operation;
			break;
		}

		case 9:
		{
			int size;

			cout << "Enter size of array" << endl;
			cin >> size;

			int *arr = new int[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				arr[i] = rand() % 198 - 99;
			}

			for (int i = 0; i < size; i++) {
				tree.add(arr[i]);
			}

			choose();
			cin >> operation;
			break;
		}

		case 10:
		{
			cout << "Work was finished" << endl;
			break;
		}

		default:
			cout << "Dzibil" << endl;

		}
	}
}