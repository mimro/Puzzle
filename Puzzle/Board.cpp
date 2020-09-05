#include "GameBase\Board.h"
#include "GameBase\Tile.h"
#include <numeric> 
#include <algorithm>
#include <time.h>

using namespace std;

typedef  vector<vector<Tile*>> BoardTable;

Board::Board(int size)
{
	this->size = size;
}


int Board::GetValueAt(int x, int y)
{
	return board[x][y]->GetValue();
}

vector<vector<int>> Board::GetBoardAsInt()
{
	vector<vector<int>> boardAsInt(size,vector<int>(size));

	for(int i=0;i<size;i++)
		for (int j = 0; j < size; j++)
		{
			boardAsInt[i][j] = board[i][j]->GetValue();
		}

	return boardAsInt;
}


Tile Board::GetEmptyTile()
{
	for (int y = 0; y<this->size; y++)
		for (int x = 0; x < this->size; x++)
		{
			if (this->board[x][y]->GetValue() == 0)
			{
				return *board[x][y];
			}
		}
}

Tile Board::GetTileAt(int x,int y)
{
	return *board[x][y];
}

void Board::SwapValues(Tile clickedTile, Tile emptyTile)
{
	int val = board[clickedTile.X][clickedTile.Y]->GetValue();
	board[clickedTile.X][clickedTile.Y]->SetValue(board[emptyTile.X][emptyTile.Y]->GetValue());
	board[emptyTile.X][emptyTile.Y]->SetValue(val);
}

static bool isSolvable(vector<int> v_board, int size)
{
	int inv_count = 0;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (v_board[j] && v_board[i] && v_board[i] > v_board[j])
				inv_count++;
	return (inv_count % 2 == 0);
}

bool isFinalSetup(vector<int> v) {
	for (int i = 0; i < v.size()-1; i++)
	{
		if(v[i] != i)
			return false;
	}
	return true;
}

void Board::GenerateRandomBoard()
{
	this->board = *new BoardTable(size, vector<Tile*>(size));
	vector<int> v(this->size * this->size);
	iota(begin(v), end(v), 0);
	srand(time(0));
	do
	{
		random_shuffle(v.begin(), v.end());
	} while (!isSolvable(v,size));

	int iter = 0;
	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
		{
			Tile* tile = new Tile(x, y, v[iter]);
			board[x][y] = tile;
			iter++;
		}
}

MoveVector Board::MakeMove(int x, int y)
{
	Tile clickedTile = GetTileAt(x, y);
	Tile emptyTile = GetEmptyTile();
	int tileValue = clickedTile.GetValue();
	if (clickedTile.X == emptyTile.X)
	{
		if (clickedTile.Y == emptyTile.Y - 1) {
			SwapValues(clickedTile, emptyTile);
			return{ 0,1,tileValue };
		}
		else if (clickedTile.Y == emptyTile.Y + 1) {
			SwapValues(clickedTile, emptyTile);
			return{ 0,-1,tileValue };
		}
	}
	else if (clickedTile.Y == emptyTile.Y)
	{
		if (clickedTile.X == emptyTile.X - 1)
		{
			SwapValues(clickedTile, emptyTile);
			return{ 1,0,tileValue };
		}
		else if (clickedTile.X == emptyTile.X + 1)
		{
			SwapValues(clickedTile, emptyTile);
			return{ -1,0,tileValue };
		}
	}

	return{ 0,0, tileValue };
}

bool Board::IsGameFinished()
{
	int iter = 1;
	for (int i = 0; i < size; i++)
		for(int j=0; j<size; j++)
	{
			if (board[i][j]->GetValue() != iter)
			{
				return false;
			}

			iter++;
	}
	return true;
}

template<typename T>
void  Board::ToOneDimensionBoard(vector<T> const& board) {
	vector<T> oneDimBoard;

	board1D.reserve(board.size()*board.size());
	for (auto& items : board) {
		move(items.begin(), items.end(), back_inserter(oneDimBoard));
	}
	return oneDimBoard;
}

Board::~Board()
{
}