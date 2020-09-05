#pragma once
#include "Solver.h"
class GreedyBestFirstSolver :
	public Solver
{
public:
	GreedyBestFirstSolver();
	~GreedyBestFirstSolver();
	Node* Solve(vector<vector<int>> initialBoard) override;
};

