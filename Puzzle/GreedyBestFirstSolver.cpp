#include "Solver\GreedyBestFirstSolver.h"
#include "Solver\CostNoDepthFunctor.h"


GreedyBestFirstSolver::GreedyBestFirstSolver()
{
}


GreedyBestFirstSolver::~GreedyBestFirstSolver()
{
}

Node* GreedyBestFirstSolver::Solve(vector<vector<int>> initialBoard)
{
	coordinates c = GetEmptyTileCoordinates(initialBoard);

	priority_queue<Node*, vector<Node*>, CostNoDepthFunctor> nodes;
	set<vector<int>> visitedNodes;
	Node* firstNode = CreateNode(initialBoard, c.X, c.Y, c.X, c.Y, 0, NULL);

	vector<int> board1D = ToBoard1D(initialBoard);
	firstNode->cost = CalculateManhattanCost(board1D, initialBoard.size());

	nodes.push(firstNode);
	visitedNodes.insert(board1D);
	while (!nodes.empty())
	{
		Node* minCostNode = nodes.top();

		nodes.pop();
		if (minCostNode->cost == 0)
		{
			return minCostNode;
		}

		if (visitedNodes.size() > 5000)
		{
			return NULL;
		}

		for (int i = 0; i < 4; i++)
		{
			if (CanMove(minCostNode->x + row[i], minCostNode->y + col[i], initialBoard.size()))
			{
				Node* child = CreateNode(minCostNode->board, minCostNode->x,
					minCostNode->y, minCostNode->x + row[i],
					minCostNode->y + col[i],
					minCostNode->level + 1, minCostNode);
				vector<int> b = ToBoard1D(child->board);
				if (!visitedNodes.count(b))
				{
					child->cost = CalculateManhattanCost(b, child->board.size());
					nodes.push(child);
					visitedNodes.insert(b);
				}
			}
		}
	}

}