#pragma once
#include <string>

struct Piece
{
	std::string type;
	char colour;
	bool pieceIsPresent = false;
};

struct Position
{
	int x;
	int y;
	bool isValid = false;
};