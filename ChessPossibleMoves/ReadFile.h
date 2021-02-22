#pragma once
#include "Piece.h"
#include <string>

extern Piece ChessBoard[8][8];

void readFile(std::string fileName);
char getPieceColour(char colour);
std::string getPieceType(char type);
int getPieceXCoordinate(char x);
int getPieceYCoordinate(char y);