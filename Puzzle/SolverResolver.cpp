#include "Solver\SolverResolver.h"
#include <chrono> 
#include <iostream>
using namespace std::chrono;

SolverResolver::SolverResolver()
{
}


SolverResolver::~SolverResolver()
{
}

stack<coordinates> SolverResolver::Solve(Solver* solver, Board board, int boardSize)
{
	stack<coordinates> coords;
	auto start = high_resolution_clock::now();

	Node* node = solver->Solve(board.GetBoardAsInt());
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	if (node == NULL) {
		cout << "Nie uda³o siê znaleŸæ rozwi¹zania w ustalonym czasie" << endl;
		 coords.push({ -1,-1 });
		 return coords;
	}

	PrintPath(node);
	coords.push({ boardSize - 1, boardSize - 1 });
	while (node->parent != NULL) {
		coords.push({ node->parent->x, node->parent->y });
		node = node->parent;
	}
	
	executionTime = duration.count();
	numberOfSteps = coords.size();
		
	PrintSolvingData();

	return coords;
}

void SolverResolver::PrintPath(Node* root)
{
	if (root == NULL)
		return;
	PrintPath(root->parent);
	PrintBoard(root->board);

	printf("\n");
}

void SolverResolver::PrintBoard(vector<vector<int>> board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}

void SolverResolver::PrintSolvingData()
{
	cout<<"Rozwi¹zywanie zaje³o: "<< executionTime/1000<< "s"  <<endl;
	cout << "Liczba kroków: " << numberOfSteps << endl;

}
