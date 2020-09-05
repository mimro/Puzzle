#pragma once
#include <vector>
#include <iterator>
#include "Node.h"

#include "GameBase\Coordinates.h"

/**
 * @class	SolverBase
 *
 * @brief	Klasa bazowa rozwi¹zywacza puzli
 *
 * @author	Michal Mroczek
 * @date	05.09.2020
 */

class SolverBase
{
public:
	SolverBase();
	~SolverBase();
protected:

	/**
	 * @fn	vector<int> SolverBase::ToBoard1D(vector<vector<int>> board);
	 *
	 * @brief	Funkcja transformuj¹ca dwy wymiarow¹ plansze na jednowymiarow¹ plansze
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	plansza gry 2D
	 *
	 * @returns	plansza gry 1D
	 */

	vector<int> ToBoard1D(vector<vector<int>> board);

	/**
	 * @fn	bool SolverBase::CanMove(int x, int y, int size);
	 *
	 * @brief	Funkcja sprawdzaj¹ca czy mo¿na poruszyæ siê na pole o danych wspó³rzêdnych
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	x   	Wspó³rzêdna x
	 * @param 	y   	Wspó³rzêdna y
	 * @param 	size	rozmiar planszy
	 *
	 * @returns	bool - czy mo¿e siê poruszyæ w dane miejsce
	 */

	bool CanMove(int x, int y, int size);

	/**
	 * @fn	Node* SolverBase::CreateNode(vector<vector<int>> mat, int x, int y, int newX, int newY, int level, Node* parent);
	 *
	 * @brief	Tworzy wskaŸnik na nowy wêze³ grafu
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 		  	board   	plansza
	 * @param 		  	x	  	Wspó³rzêdna x
	 * @param 		  	y	  	Wspó³rzêdna  y
	 * @param 		  	newX  	Nowa wspó³rzêdna x
	 * @param 		  	newY  	Nowa wspó³rzêdna y
	 * @param 		  	level 	poziom g³êbokoœci grafu
	 * @param [in,out]	parent	rodzic wêz³a grafu z którego siê wywodzi
	 *
	 * @returns	Null if it fails, else the new node.
	 */

	Node* CreateNode(vector<vector<int>> board, int x, int y, int newX,
		int newY, int level, Node* parent);

	/**
	 * @fn	coordinates SolverBase::GetEmptyTileCoordinates(vector<vector<int>> board);
	 *
	 * @brief	Znajduje wspó³rzêdne pustego kafelka 
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	board	plansza gry
	 *
	 * @returns	wspó³rzêdne pustego kafelka
	 */

	coordinates GetEmptyTileCoordinates(vector<vector<int>> board);
};

