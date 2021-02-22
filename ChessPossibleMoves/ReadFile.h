#pragma once
#include "Piece.h"
#include <string>


void readFile(std::string fileName, Piece tablica[8][8]);
char getPieceColour(char colour);
void getPieceType(char type);
int getPieceXCoordinate(char x);
int getPieceYCoordinate(char y);