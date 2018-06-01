// TestForTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Class.h"
#include "Function.h"
#include "catch.hpp"


TEST_CASE()
{
	Tree<int> tree;
	tree.add(6);
	tree.add(9);
	tree.add(5);
	REQUIRE(tree.in(6) == true);
	REQUIRE(tree.in(9) == true);
	REQUIRE(tree.in(5) == true);

	REQUIRE(tree.in(66) == false);
}

TEST_CASE() {
	Tree<int> tree;
	tree.add(6);
	tree.add(9);
	tree.add(5);

	REQUIRE(tree.getCounter() == 3);
}

TEST_CASE() {
	Tree<int> tree;
	tree.add(6);
	tree.add(9);
	tree.add(5);
	REQUIRE(tree.maximal() == 9);
}

TEST_CASE() {
	Tree<int> tree;
	tree.add(6);
	tree.add(9);
	tree.add(5);
	REQUIRE(tree.minimal() == 5);
}

TEST_CASE()
{
	Tree<int> tree;

	tree.add(10);
	tree.add(8);
	tree.add(15);
	tree.add(7);
	tree.add(9);
	tree.add(14);
	tree.add(16);

	tree.remove(16); // листок

	REQUIRE(tree.getCounter() == 6);

}

TEST_CASE()
{
	Tree<int> tree;

	tree.add(10);
	tree.add(8);
	tree.add(15);
	tree.add(7);
	tree.add(9);
	tree.add(14);
	tree.add(16);

	tree.remove(15); // 2 нащадка

	REQUIRE(tree.getCounter() == 6);

}


TEST_CASE()
{
	Tree<int> tree;

	tree.add(10);
	tree.add(8);
	tree.add(15);
	tree.add(7);
	tree.add(9);
	tree.add(14);
	tree.add(16);

	tree.print();
	cout << endl;
	cout << endl;

	tree.remove(10); // корінь
	REQUIRE(tree.getCounter() == 6);
	tree.print();
	cout << endl;
	cout << endl;
}