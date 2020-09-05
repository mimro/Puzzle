#include "PuzzleGameView\SFMLView.h"
#include "GameBase\Board.h"
#include "ActionResult.h"
#include "Solver\Solver.h"
#include "GameStates.h"

/**
 * @class	GameManager
 *
 * @brief	Klasa menad�era gry - zarz�dza przebiegiem gry
 *
 * @author	Micha� Mroczek
 * @date	05.09.2020
 */

class GameManager
{
private:
	Board* board;
	int windowSize;
	int state;
	int boardSize;
	string texturePath;
	int selectView;
	IView *view;
	Solver* solver;
	ActionResult GetAction();
	void InitializeSolver();
public:

	/**
	 * @fn	GameManager::GameManager();
	 *
	 * @brief	Konstruktor
	 *
	 * @author	Micha� Mroczek
	 * @date	04.09.2020
	 */
	GameManager();

	/**
	 * @fn	GameManager::~GameManager();
	 *
	 * @brief	Destruktor
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 */
	~GameManager();

	/**
	 * @fn	void GameManager::Setup();
	 *
	 * @brief	Funkcja ustawiaj�ca stan mened�era gry
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 */
	void Setup();

	/**
	 * @fn	void GameManager::WriteMenuText();
	 *
	 * @brief	Wypisuje pocz�tkowe menu do konsoli gry
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 */
	void WriteMenuText();

	/**
	 * @fn	void GameManager::Run();
	 *
	 * @brief	Funkcja p�tli gry
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 */
	void Run();

};

