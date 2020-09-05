#pragma once
#include "Solver.h""
class SolverFactory
{
public:
	SolverFactory();
	~SolverFactory();
	Solver* GetSolverAlgorithm(int solverAlgoritmSelection);

private:	
	Solver* solver;
};

