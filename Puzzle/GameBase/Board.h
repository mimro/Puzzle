#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Tile.h"
#include "MakeMoveVector.h"

using namespace std;

/**
* Klasa opisuj¹ca plansze gry
*/
class Board
{
typedef  vector<vector<Tile*>> BoardTable;

protected:
	int size;
	BoardTable board;

public:
	/**
	* Kontruktor inicjalizuje plansze o danym rozmiarze
	*/
	Board(int size);

	/**
	 * Domyœlny destruktor planszy
	 */

	~Board();
	/**
	* Funkcja zwracaj¹ca pusty kafelek
	*/
	Tile GetEmptyTile();

	/**
	* Funkcja zwracaj¹ca kafelek o danych wspó³rzêdnych
	*/
	Tile GetTileAt(int x,int y);

	/**
	* Funkcja zwracaj¹ca wartoœæ kafelka o danych wspó³rzêdnych
	*/
	int GetValueAt(int x, int y);

	/**
	* Funkcja zwracaj¹ca plansze gry jako dwu wymiarowy wektor o typie int
	*/
	vector<vector<int>> GetBoardAsInt();

	/**
	* Funkcja generuj¹ca losowe wartoœci i przypisuj¹ca je do planszy
	*/
	void GenerateRandomBoard();

	/**
	* Funkcja do wykonywania ruchu o wsp
	*/
	MoveVector MakeMove(int x, int y);
	bool IsGameFinished();


private:
	void SwapValues(Tile clickedTile, Tile emptyTile);

	template<typename T>
	void ToOneDimensionBoard(std::vector<T> const& board);
};



#endif 

