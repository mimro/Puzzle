#include "Solver\Solver.h"

Solver::Solver()
{
}


Solver::~Solver()
{
}

int Solver::CalculateHammingCost(vector<int> board1D)
{	
		int cost = 0;

		for (unsigned int i = 0; i < board1D.size(); i++)
		{
			if (board1D[i] == 0) continue;
			if (board1D[i] != i + 1) cost += 1;
		}
		return cost;
}

int Solver::CalculateManhattanCost(vector<int> board1D, int size)
{
	int cost = 0;
	for (int i = 0; i < board1D.size(); ++i)
	{
		int v = board1D[i];
		if (v == 0) continue;

		v = v - 1;
		int gx = v % size;
		int gy = v / size;

		int x = i % size;
		int y = i / size;

		int mancost = abs(x - gx) + abs(y - gy);
		cost += mancost;
	}
	return cost;
}

