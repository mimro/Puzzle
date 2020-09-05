#pragma once
#include <vector>
#include <queue>
#include <set>
#include <cstdint>
#include <cstring>
#include "Node.h"
#include <algorithm>
#include "GameBase\Coordinates.h"
#include <iterator>
#include "SolverBase.h"

using namespace std;

/**
 * @class	Solver
 *
 * @brief	Klasa rozwi�zywacza puzli
 *
 * @author	Michal Mroczek
 * @date	05.09.2020
 */

class Solver : public SolverBase
{
public:

	/**
	 * @fn	Solver::Solver();
	 *
	 * @brief	Konstruktor
	 *
	 * @author	Dell
	 * @date	05.09.2020
	 */

	Solver();
	~Solver();

	/**
	 * @fn	virtual Node* Solver::Solve(vector<vector<int>> initialBoard) = 0;
	 *
	 * @brief	Funkcja rozwi�zywuj�ca puzzle o danej planszy
	 *
	 * @author	Dell
	 * @date	05.09.2020
	 *
	 * @param 	initialBoard	Pocz�tkowa plansza
	 *
	 * @returns	Zwraca wska�nik na ostatni w�ze� grafu
	 */

	virtual Node* Solve(vector<vector<int>> initialBoard) = 0;

protected:
	 const int row[4] = { 1, 0, -1, 0 };
	 const int col[4] = { 0, -1, 0, 1 };

	 /**
	  * @fn	int Solver::CalculateHammingCost(vector<int> board1D);
	  *
	  * @brief	Funkcja licz�ca koszt danego w�z�a wed�ug odleg�o�ci Hamminga https://pl.wikipedia.org/wiki/Odleg%C5%82o%C5%9B%C4%87_Hamminga
	  *
	  * @author	Michal Mroczek
	  * @date	05.09.2020
	  *
	  * @param 	Jednowymiarowa plansza gry
	  *
	  * @returns Wyliczony koszt Hamminga
	  */

	 int CalculateHammingCost(vector<int> board1D);

	 /**
	  * @fn	int Solver::CalculateManhattanCost(vector<int> board1D, int size);
	  *
	  * @brief	Funkcja licz�ca koszt danego w�z�a wed�ug odleg�o�ci Manhattan https://en.wiktionary.org/wiki/Manhattan_distance
	  *
	  * @author	Michal Mroczek
	  * @date	05.09.2020
	  *
	  * @param 	board1D	Jednowymiarowa plansza gry
	  * @param 	size   	The size.
	  *
	  * @returns Wyliczony koszt Manhattan
	  */

	 int CalculateManhattanCost(vector<int> board1D, int size);
};

