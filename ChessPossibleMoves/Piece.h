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
	bool isValid = false;
	int x;
	int y;
};