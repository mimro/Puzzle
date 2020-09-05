#pragma once
#include "Solver.h"
#include "GameBase\Board.h"
#include <stack>
using namespace std;

/**
 * @class	SolverResolver
 *
 * @brief	Klasa zarz¹dzaj¹ca przebiegiem rozwi¹zywania puzzli i pobieraniu potrzebnych parametrów
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
	 * @brief	Funkcja wywo³uj¹ca funkcje solvera - solve
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param [in,out]	solver   	Rozwi¹zywacz
	 * @param 		  	board	 	Plansza gry
	 * @param 		  	boardSize	Rozmiar planszy
	 *
	 * @returns	Zwraca stos wspó³rzêdnych potrzebnych do rozwi¹zania puzli
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
	 * @param wskaŸnik na wenze³ grafu
	 */
	void PrintPath(Node* root);

	/**
	 * @fn	void SolverResolver::PrintBoard(vector<vector<int>> mat);
	 *
	 * @brief	Funkcja wypisuj¹ca plansze do konsoli
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
	 * @brief	Wypisuje dane rozwi¹zania
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 */
	void PrintSolvingData();
private:
	double executionTime;
	int numberOfSteps;
};

