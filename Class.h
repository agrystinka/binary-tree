#pragma once

template<typename T>
class Tree
{
private:
	class Node {
	public:
		T data;
		Node *left;
		Node *right;
		Node *parent;

		Node(T data, Node*parent) { //конструктор
			this->data = data;
			this->left = NULL;
			this->right = NULL;
			this->parent = parent;

		}
	};
	Node *root;
	int count;

	Node *del(Node *root, T data)
	{	// якщо дерева немає або значення не в дереві

		if (!root)
		{
			throw logic_error("Deleting element from empty tree");
		}
		auto node = root;
		while (node)
		{
			if (data == node->data) break;
			if (data < node->data)
			{
				if (!node->left) return NULL;
				node = node->left;
				continue;
			}
			if (data > node->data)
			{
				if (!node->right) return NULL;
				node = node->right;
				continue;
			}
		}
		if (!node->left && !node->right)
		{
			delete node;
			count--;
			return NULL;
		}
		if (node->left)
		{
			auto currentNode = node->left;
			while (currentNode->right)
			{
				currentNode = currentNode->right;
			}
			node->data = currentNode->data;
			if (currentNode->left)
			{
				currentNode->left->parent = currentNode->parent;
			}
			if (currentNode->parent)
			{
				currentNode->parent->right = currentNode->left;
			}
			delete currentNode;
			count--;
			return NULL;
		}
		if (node->right)
		{
			auto currentNode = node->right;
			while (currentNode->right)
			{
				currentNode = currentNode->right;
			}
			node->data = currentNode->data;
			if (currentNode->right)
			{
				currentNode->right->parent = currentNode->parent;
			}
			if (currentNode->parent)
			{
				currentNode->parent->left = currentNode->right;
			}
			delete currentNode;
			count--;
		}

	}

	void printTree(Node*root, const char *dir, int level);

	int min(Node *root);

	int max(Node *root);

	bool inTree(Node *root, T data);

	int heightOfTree(Node * root);

public:
	Tree();

	Tree(T data);

	~Tree();

	void add(T data);

	void print();

	int minimal();

	int maximal();

	void remove(T data);

	bool in(T data);

	int getCounter();

	int height();

};
