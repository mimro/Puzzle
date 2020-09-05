#ifndef TILE_H
#define TILE_H

/**
 * @class	Tile
 *
 * @brief	Klasa opisuj�ca kafelek
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
	 * @param 	x	 	wsp�rz�dna x 
	 * @param 	y	 	wsp�rz�dna y
	 * @param 	value	warto��
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
	 * @brief	Funkcja zwracaj�ca warto�� kafelka
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
	 * @brief	Funkcja ustawia�ca warto�� kafelka
	 *
	 * @author	Michal Mroczek
	 * @date	04.09.2020
	 *
	 * @param 	value	The value.
	 */
	void SetValue(int value);
};

#endif