#pragma once
#include <vector>
#include "Solver.h"
using namespace std;

class DFSSolver: public Solver
{
public:
	DFSSolver();
	~DFSSolver();
 	Node* Solve(vector<vector<int>> initialBoard) override;
};

