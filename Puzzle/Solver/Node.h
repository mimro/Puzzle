#pragma once
#include <vector>
using namespace std;
struct Node
{
	Node* parent;

	vector<vector<int>> board;

	int x, y;

	int cost;

	int level;
};