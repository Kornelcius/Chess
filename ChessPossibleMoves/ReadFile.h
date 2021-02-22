#pragma once
#include "Piece.h"
#include <string>


void readFile(std::string fileName, Piece tablica[8][8]);
void getPieceColour(char colour);
void getPieceType(char type);
void getPiecePosition(char x, char y);
