// TestOnly.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Class.h"
#include "Function.h"

using namespace std;


int main() {
	Tree<int> tree;

	workWithTree(tree);
	
	return 0;
}

