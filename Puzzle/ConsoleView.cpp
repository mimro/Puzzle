#include "PuzzleGameView\ConsoleView.h"
#include <iostream>
#include <conio.h>
using namespace std;

ConsoleView::ConsoleView()
{
}


ConsoleView::~ConsoleView()
{
}

void ConsoleView::Setup(int _boardSize, string TexturePath)
{
	boardSize = _boardSize;
}

bool ConsoleView::CanMove(int x, int y, int size)
{
	return (x >= 0 && x < size && y >= 0 && y < size);
}

ActionResult ConsoleView::GetAction()
{
	char c = _getch();
	if (c == (int)'s')
	{
		return{ 0,0,false, SOLVING};
	}

	int x = 0, y = 0;
	bool canMove = true;
	do {
		cout <<endl<< "Podaj wartoœæ x: ", cin >> x;
		cout << "Podaj wartoœæ y: ",cin>>y;

		canMove = CanMove(x, y, boardSize);
		if (canMove == false)
		{
			cout << "nieprawid³owe dane" << endl;
		}
	} while (!canMove);

	return{ x,y,true };
}

void ConsoleView::MakeMove(Board * board, int x, int y)
{
	
	MoveVector moveVector = board->MakeMove(x, y);
}

void ConsoleView::RenderBoard(Board board)
{
	vector<vector<int>> boardInt = board.GetBoardAsInt();
	for (int i = 0; i < boardInt.size(); i++)
	{
		for (int j = 0; j < boardInt.size(); j++)
			printf("%d ", boardInt[i][j]);
		printf("\n");
	}
}
