#pragma once
#include "Solver.h"
class AStarSolver :
	public Solver
{
public:
	AStarSolver();
	~AStarSolver();
	Node* Solve(vector<vector<int>> initialBoard) override;
};

