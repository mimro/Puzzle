#include "Solver\SolverBase.h"

SolverBase::SolverBase()
{
}


SolverBase::~SolverBase()
{
}

coordinates SolverBase::GetEmptyTileCoordinates(vector<vector<int>> board)
{
	int x = 0, y = 0;
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == 0)
			{
				return{ i,j };
				break;
			}
		}
}

vector<int> SolverBase::ToBoard1D(vector<vector<int>> board)
{
	vector<int> board1D;

	board1D.reserve(board.size()*board.size());
	for (auto& items : board) {
		std::move(items.begin(), items.end(), std::back_inserter(board1D));
	}
	return board1D;
}

bool SolverBase::CanMove(int x, int y, int size)
{
	return (x >= 0 && x < size && y >= 0 && y < size);
}

Node * SolverBase::CreateNode(vector<vector<int>> board, int x, int y, int newX, int newY, int level, Node * parent)
{

	Node* node = new Node;
	node->parent = parent;
	node->board = board;
	swap(node->board[x][y], node->board[newX][newY]);
	node->cost = INT_MAX;
	node->level = level;
	node->x = newX;
	node->y = newY;

	return node;

}