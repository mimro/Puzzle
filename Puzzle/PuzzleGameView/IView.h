#pragma once
#include "GameBase\Board.h"
#include "GameManager\ActionResult.h"

/**
 * @class	IView
 *
 * @brief	Interfejs (klasa abstrakcyjna) widoku - odpowiada za wyœwietlenie planszy na ekranie
 *
 * @author	Michal Mroczek
 * @date	05.09.2020
 */

class IView
{
public:
	 IView();
	~IView();

	/**
	 * @fn	virtual void IView::Setup(int size) = 0;
	 *
	 * @brief	Ustawia parametry widoku
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	size Rozmiar planszy
	 */

	virtual void Setup(int size, string TexturePath) = 0;

	/**
	 * @fn	virtual ActionResult IView::GetAction() = 0;
	 *
	 * @brief	Funkcja obs³uguj¹ca akcje na widoku
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @returns	Zwraca strukture ActionResult
	 */

	virtual ActionResult GetAction() = 0;

	/**
	 * @fn	virtual void IView::MakeMove(Board* board, int x, int y) = 0;
	 *
	 * @brief funkcja obs³uguj¹ca wykonanie ruchu
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param [in,out]	board	plansza.
	 * @param 		  	x	 	wspó³rzêdna x.
	 * @param 		  	y	 	wspó³rzêdna y.
	 */

	virtual void MakeMove(Board* board, int x, int y) = 0;

	/**
	 * @fn	virtual void IView::RenderBoard(Board board) = 0;
	 *
	 * @brief Funkcja wyœwietlaj¹ca plansze gry
	 *
	 * @author	Michal Mroczek
	 * @date	05.09.2020
	 *
	 * @param 	board	Plansza gry.
	 */

	virtual void RenderBoard(Board board) = 0;
};

