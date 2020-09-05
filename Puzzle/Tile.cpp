#include "GameBase\Tile.h"

Tile::Tile(int _x, int _y, int _value)
{
		value = _value;
		X = _x;
		Y = _y;
}


Tile::~Tile()
{
}

int Tile::GetValue()
{
	return value;
}

void Tile::SetValue(int value)
{
	this->value = value;
}
