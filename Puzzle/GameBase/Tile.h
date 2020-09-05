#ifndef TILE_H
#define TILE_H

/**
 * @class	Tile
 *
 * @brief	Klasa opisuj¹ca kafelek
 *
 * @author	Michal Mroczek
 * @date	04.09.2020
 */

class Tile
{
protected:
	int value;  
public:
	int X, Y;

	/**
	 * @fn	Tile::Tile(int x, int y, int value);
	 *
	 * @brief	Kontruktor kafelka
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 *
	 * @param 	x	 	wspórzêdna x 
	 * @param 	y	 	wspó³rzêdna y
	 * @param 	value	wartoœæ
	 */

	Tile(int x, int y, int value);

	/**
	 * @fn	Tile::~Tile();
	 *
	 * @brief	Destruktor
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 */

	~Tile();

	/**
	 * @fn	int Tile::GetValue();
	 *
	 * @brief	Funkcja zwracaj¹ca wartoœæ kafelka
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 *
	 * @returns	The value.
	 */
	int GetValue();

	/**
	 * @fn	void Tile::SetValue(int value);
	 *
	 * @brief	Funkcja ustawia¹ca wartoœæ kafelka
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 *
	 * @param 	value	The value.
	 */
	void SetValue(int value);
};

#endif