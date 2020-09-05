#include "Solver\SolverFactory.h"
#include "Solver\DFSSolver.h"
#include "Solver\AStarSolver.h"
#include "Solver\GreedyBestFirstSolver.h"

SolverFactory::SolverFactory()
{
}


SolverFactory::~SolverFactory()
{
}

Solver* SolverFactory::GetSolverAlgorithm(int solverAlgoritmSelection)
{
	switch (solverAlgoritmSelection)
	{
	case 1:
		solver = new DFSSolver();
		break;
	case 2:
		solver = new AStarSolver();
		break;
	case 3:
		solver = new GreedyBestFirstSolver();
	}

	return solver;
}
