#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Tile.h"
#include "MakeMoveVector.h"

using namespace std;

/**
* Klasa opisuj�ca plansze gry
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
	 * Domy�lny destruktor planszy
	 */

	~Board();
	/**
	* Funkcja zwracaj�ca pusty kafelek
	*/
	Tile GetEmptyTile();

	/**
	* Funkcja zwracaj�ca kafelek o danych wsp�rz�dnych
	*/
	Tile GetTileAt(int x,int y);

	/**
	* Funkcja zwracaj�ca warto�� kafelka o danych wsp�rz�dnych
	*/
	int GetValueAt(int x, int y);

	/**
	* Funkcja zwracaj�ca plansze gry jako dwu wymiarowy wektor o typie int
	*/
	vector<vector<int>> GetBoardAsInt();

	/**
	* Funkcja generuj�ca losowe warto�ci i przypisuj�ca je do planszy
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

