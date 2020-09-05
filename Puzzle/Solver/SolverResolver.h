#pragma once
#include "Solver.h"
#include "GameBase\Board.h"
#include <stack>
using namespace std;

/**
 * @class	SolverResolver
 *
 * @brief	Klasa zarz�dzaj�ca przebiegiem rozwi�zywania puzzli i pobieraniu potrzebnych parametr�w
 *
 * @author	Michal Mroczek
 * @date	05.09.2020
 */

class SolverResolver
{
public:
	SolverResolver();
	~SolverResolver();

	/**
	 * @fn	stack<coordinates> SolverResolver::Solve(Solver* solver, Board board, int boardSize);
	 *
	 * @brief	Funkcja wywo�uj�ca funkcje solvera - solve
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param [in,out]	solver   	Rozwi�zywacz
	 * @param 		  	board	 	Plansza gry
	 * @param 		  	boardSize	Rozmiar planszy
	 *
	 * @returns	Zwraca stos wsp�rz�dnych potrzebnych do rozwi�zania puzli
	 */

	stack<coordinates> Solve(Solver* solver, Board board, int boardSize);

	/**
	 * @fn	void SolverResolver::PrintPath(Node* root);
	 *
	 * @brief	Wypisuje kolejne statusy planszy puzzli do konsoli
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param wska�nik na wenze� grafu
	 */
	void PrintPath(Node* root);

	/**
	 * @fn	void SolverResolver::PrintBoard(vector<vector<int>> mat);
	 *
	 * @brief	Funkcja wypisuj�ca plansze do konsoli
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	plansza gry
	 */
	void PrintBoard(vector<vector<int>> board);

	/**
	 * @fn	void SolverResolver::PrintSolvingData();
	 *
	 * @brief	Wypisuje dane rozwi�zania
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 */
	void PrintSolvingData();
private:
	double executionTime;
	int numberOfSteps;
};

