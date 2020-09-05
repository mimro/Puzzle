#pragma once
#include <vector>
#include <iterator>
#include "Node.h"

#include "GameBase\Coordinates.h"

/**
 * @class	SolverBase
 *
 * @brief	Klasa bazowa rozwi�zywacza puzli
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
	 * @brief	Funkcja transformuj�ca dwy wymiarow� plansze na jednowymiarow� plansze
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
	 * @brief	Funkcja sprawdzaj�ca czy mo�na poruszy� si� na pole o danych wsp�rz�dnych
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	x   	Wsp�rz�dna x
	 * @param 	y   	Wsp�rz�dna y
	 * @param 	size	rozmiar planszy
	 *
	 * @returns	bool - czy mo�e si� poruszy� w dane miejsce
	 */

	bool CanMove(int x, int y, int size);

	/**
	 * @fn	Node* SolverBase::CreateNode(vector<vector<int>> mat, int x, int y, int newX, int newY, int level, Node* parent);
	 *
	 * @brief	Tworzy wska�nik na nowy w�ze� grafu
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 		  	board   	plansza
	 * @param 		  	x	  	Wsp�rz�dna x
	 * @param 		  	y	  	Wsp�rz�dna  y
	 * @param 		  	newX  	Nowa wsp�rz�dna x
	 * @param 		  	newY  	Nowa wsp�rz�dna y
	 * @param 		  	level 	poziom g��boko�ci grafu
	 * @param [in,out]	parent	rodzic w�z�a grafu z kt�rego si� wywodzi
	 *
	 * @returns	Null if it fails, else the new node.
	 */

	Node* CreateNode(vector<vector<int>> board, int x, int y, int newX,
		int newY, int level, Node* parent);

	/**
	 * @fn	coordinates SolverBase::GetEmptyTileCoordinates(vector<vector<int>> board);
	 *
	 * @brief	Znajduje wsp�rz�dne pustego kafelka 
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	board	plansza gry
	 *
	 * @returns	wsp�rz�dne pustego kafelka
	 */

	coordinates GetEmptyTileCoordinates(vector<vector<int>> board);
};

